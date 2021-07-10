#include <iostream>
#include <string>
#include <vector>

typedef std::vector<std::string> MyStringVector;
typedef std::vector<std::string>::iterator MyIterator;

std::string justifyParagraph(const std::string &, int);
MyStringVector getParagraphWords(const std::string &);
std::string getFormattedRow(MyIterator &, MyIterator &, int, int, bool);
void printVector(MyStringVector &);

int main() {

	std::string originalParagraph = "New component JYScrollPaneMap which is pretty useful    for large scrollpane views";
	std::cout << originalParagraph << std::endl;

	std::string formattedParagraph = justifyParagraph(originalParagraph, 5);
	std::cout << formattedParagraph << std::endl;
}

std::string justifyParagraph(const std::string & input, int targetLength) {

	MyStringVector words = getParagraphWords(input);
	printVector(words);

	int rowCharCount = 0;
	int rowSpacesCount = -1;

	std::string formatted = "";
	MyIterator rowFirstWord = words.begin();
    MyIterator rowLastWord = words.begin();

	std::cout << std::endl;
	for(MyIterator word = words.begin(); word < words.end(); ) {
		
		if((rowCharCount == 0) || (rowCharCount + rowSpacesCount + 1 + word->length() < targetLength)) {

			rowLastWord = word;
			++rowSpacesCount;
			rowCharCount += word->length();

			std::cout << *word << " (" << word->length() << ") -> " << "fits: char (" << rowCharCount << "), spaces (" << rowSpacesCount << ") => row (" << rowCharCount + rowSpacesCount << ")" << std::endl;

			if(++word == words.end()) formatted += getFormattedRow(rowFirstWord, rowLastWord, rowCharCount, targetLength, true);

		} else {
			
			formatted += getFormattedRow(rowFirstWord, rowLastWord, rowCharCount, targetLength, false);

			rowCharCount = 0;
			rowSpacesCount = -1;

			rowFirstWord = word;
			rowLastWord = rowFirstWord;

			std::cout << std::endl;
		}
	}

	std::cout << std::endl;

	return formatted;
}


MyStringVector getParagraphWords(const std::string & paragraph) {

	std::string newWord = "";
	MyStringVector words;

	for(char character : paragraph) {

		if(character != ' ') { 
		
			newWord += character;
		
		} else if(!newWord.empty()) {

			words.push_back(newWord);
			newWord.clear();
		}
	}

	if(!newWord.empty()) words.push_back(newWord);

	return words;
}

std::string getFormattedRow(MyIterator & rowFirstWord, MyIterator & rowLastWord, int rowCharCount, int targetLength, bool isLastRow) {

	int rowSpacesCount = 0;
	std::string formatted = "";

	std::cout << std::endl;
	for(MyIterator it = rowFirstWord; it < rowLastWord + 1; ) {
		
		std::cout << "\trendering: " << *it << ", char (" << rowCharCount << "), spaces (" << rowSpacesCount << ") => row (" << rowCharCount + rowSpacesCount << ")" << std::endl;

		if((rowCharCount + rowSpacesCount >= targetLength - 1) || rowFirstWord == rowLastWord) break;
		else if(isLastRow && it == rowLastWord) break;
		else if(it == rowLastWord) it = rowFirstWord;
		else {
			
			*it += ' ';
			++rowSpacesCount;
			++it;
		}
	}

	for(MyIterator it = rowFirstWord; it < rowLastWord + 1; ++it) formatted += *it;

	return formatted += "\n";
}

void printVector(MyStringVector & vctr) {

    if(vctr.empty()) std::cout << "[ empty ]";
    else {

		std::cout << "[ ";
        for(std::string str : vctr ) std::cout << "\"" << str << "\" ";
        std::cout << "]" << std::endl;
    }
}