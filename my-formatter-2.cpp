#include <iostream>
#include <string>
#include <vector>

typedef std::vector<std::string> MyStringVector;
typedef MyStringVector::iterator MyVectorIterator;

std::string justifyParagraph(const std::string &, int);
std::string justifyDocument(const std::string &, int);
MyStringVector getParagraphs(const std::string &);
MyStringVector getParagraphWords(const std::string &);
std::string getFormattedRow(MyVectorIterator &, MyVectorIterator &, int, int, bool);
void printVector(MyStringVector &);

int main() {

	std::string originalText = "\tLorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent sapien tortor, iaculis quis velit et, vulputate pretium ante. Integer at magna porttitor urna rutrum consectetur. Vestibulum eget felis tempor, tincidunt magna sed, porta est. Suspendisse ullamcorper justo interdum tristique commodo. Suspendisse eu ligula leo. Cras dapibus dapibus consequat. Aliquam id ipsum quis ipsum luctus pellentesque sed nec elit. Curabitur interdum tortor et rutrum mattis. Integer molestie vel magna vitae aliquam. Suspendisse dignissim non felis eget venenatis. Etiam tempus sodales malesuada. Phasellus sed vehicula mi, a maximus ex.\n\n\tInteger rutrum diam et diam dictum, eget finibus nibh vehicula. Etiam rutrum id sapien blandit tempus. In hac habitasse platea dictumst. Morbi finibus risus ut enim egestas, sed tempor mi feugiat. Quisque non turpis non ante placerat maximus. Proin porttitor ex eget neque pulvinar tincidunt. Curabitur quis augue a nulla consequat feugiat. Quisque enim metus, imperdiet sit amet suscipit auctor, vulputate eget ex.\n\n\tIn sit amet libero massa. Nunc tellus nunc, sagittis eget risus ut, malesuada gravida mi. In finibus tellus et ex congue ultrices sed nec eros. Nulla facilisi. Proin mattis lorem quis nisi pretium finibus. Morbi tempor tellus vel nisi dapibus, et porttitor nibh semper. Quisque bibendum ex eget risus hendrerit gravida. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae; Integer imperdiet eros sed neque dignissim rutrum. Pellentesque eget posuere est, at consectetur tellus. Donec diam nisl, luctus et nibh nec, tempor condimentum eros. Integer venenatis dolor quam, eget condimentum erat mollis id. Aenean cursus lorem in faucibus pretium. Morbi eget tristique diam.\n\n\tFusce rhoncus justo nisl, ut faucibus est rutrum a. Vivamus nisi velit, imperdiet sit amet accumsan id, eleifend sed mauris. Aenean vulputate mauris at dui vulputate, vitae luctus turpis vulputate. Vestibulum massa sem, fringilla a dignissim vitae, pulvinar at elit. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae; Cras consectetur a magna et varius. Integer sed metus facilisis, porta metus ac, aliquet magna. Ut auctor nibh non massa aliquet dignissim.\n\n\tLorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent sapien tortor, iaculis quis velit et, vulputate pretium ante. Integer at magna porttitor urna rutrum consectetur. Vestibulum eget felis tempor, tincidunt magna sed, porta est. Suspendisse ullamcorper justo interdum tristique commodo. Suspendisse eu ligula leo. Cras dapibus dapibus consequat. Aliquam id ipsum quis ipsum luctus pellentesque sed nec elit. Curabitur interdum tortor et rutrum mattis. Integer molestie vel magna vitae aliquam. Suspendisse dignissim non felis eget venenatis. Etiam tempus sodales malesuada. Phasellus sed vehicula mi, a maximus ex.";
/* 	std::string originalText = "New component JYScrollPaneMap which is pretty useful    for large scrollpane views"; */
	std::cout << originalText << std::endl;

	std::string formattedParagraph = justifyDocument(originalText, 70);
	std::cout << formattedParagraph << std::endl;
}

std::string justifyDocument(const std::string & input, int targetLength) {

	std::string formatted = "";

	MyStringVector text = getParagraphs(input);

	for(auto paragraph : text) formatted += justifyParagraph(paragraph, targetLength);

	return formatted;
}

std::string justifyParagraph(const std::string & input, int targetLength) {

	MyStringVector words = getParagraphWords(input);
	printVector(words);

	int rowCharCount = 0;
	int rowSpacesCount = -1;

	std::string formatted = "";
	MyVectorIterator rowFirstWord = words.begin();
    MyVectorIterator rowLastWord = words.begin();

	std::cout << std::endl;
	for(MyVectorIterator word = words.begin(); word < words.end(); ) {
		
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

MyStringVector getParagraphs(const std::string & text) {

	std::string paragraph = "";
	MyStringVector paragraphVector;

	for(char character : text) {

		if(character != '\n') { 
		
			paragraph += character;
		
		} else {

			paragraph += character;
			paragraphVector.push_back(paragraph);
			paragraph.clear();
		}
	}

	paragraphVector.push_back(paragraph);

	return paragraphVector;
}

MyStringVector getParagraphWords(const std::string & paragraph) {

	std::string newWord = "";
	MyStringVector words;

	for(char character : paragraph) {

		if(character != ' ') { 
		
			if(character != '\t') newWord += character;
			else newWord += "    ";
		
		} else if(!newWord.empty()) {

			words.push_back(newWord);
			newWord.clear();
		}
	}

	if(!newWord.empty()) words.push_back(newWord);

	return words;
}

std::string getFormattedRow(MyVectorIterator & rowFirstWord, MyVectorIterator & rowLastWord, int rowCharCount, int targetLength, bool isLastRow) {

	int rowSpacesCount = 0;
	std::string formatted = "";

	std::cout << std::endl;
	for(MyVectorIterator it = rowFirstWord; it < rowLastWord + 1; ) {
		
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

	for(MyVectorIterator it = rowFirstWord; it < rowLastWord + 1; ++it) formatted += *it;

	if(formatted.at(formatted.length() - 1) == '\n') return formatted;
	else return formatted += "\n";
}

void printVector(MyStringVector & vctr) {

    if(vctr.empty()) std::cout << "[ empty ]";
    else {

		std::cout << "[ ";
        for(std::string str : vctr ) std::cout << "\"" << str << "\" ";
        std::cout << "]" << std::endl;
    }
}