#include "paragraph.h"

Paragraph::Paragraph(const std::string & input) {

	this->m_input = input;
	this->m_formatted = "";
	this->m_targetLength = 35;
	this->m_rowSpacesCount = 0;
	this->m_rowCharCount = 0;
	
	this->getWords();
	this->format();
}

std::string Paragraph::render() const {
	
	return this->m_formatted;
}

void Paragraph::setTargetLength(int targetLength) {

	this->m_targetLength = targetLength;
}

void Paragraph::format() {

	this->m_rowCharCount = 0;
	this->m_rowSpacesCount = -1;
	this->m_formatted.clear();
	this->m_rowFirstWord = this->m_words.begin();
    this->m_rowLastWord = this->m_words.begin();

	this->getWords();

	if(DEBUG) std::cout << std::endl;
	for(auto word = this->m_words.begin(); word < this->m_words.end(); ) {
		
		if((this->m_rowCharCount == 0) || (this->m_rowCharCount + this->m_rowSpacesCount + 1 + word->length() < this->m_targetLength)) {

			this->m_rowLastWord = word;
			++this->m_rowSpacesCount;
			this->m_rowCharCount += word->length();

			if(DEBUG) std::cout << *word << " (" << word->length() << ") -> " << "fits: char (" << this->m_rowCharCount << "), spaces (" << this->m_rowSpacesCount << ") => row (" << this->m_rowCharCount + this->m_rowSpacesCount << ")" << std::endl;

			if(++word == this->m_words.end()) this->formatRow(true);

		} else {
			
			this->formatRow(false);

			this->m_rowCharCount = 0;
			this->m_rowSpacesCount = -1;

			this->m_rowFirstWord = word;
			this->m_rowLastWord = this->m_rowFirstWord;

			if(DEBUG) std::cout << std::endl;
		}
	}

	if(DEBUG) std::cout << std::endl;
}

void Paragraph::formatRow(bool isLastRow) {

	this->m_rowSpacesCount = 0;
	std::string formatted = "";

	if(DEBUG) std::cout << std::endl;
	for(auto it = this->m_rowFirstWord; it < this->m_rowLastWord + 1; ) {
		
		if(DEBUG) std::cout << "\trendering: " << *it << ", char (" << this->m_rowCharCount << "), spaces (" << this->m_rowSpacesCount << ") => row (" << this->m_rowCharCount + this->m_rowSpacesCount << ")" << std::endl;

		if((this->m_rowCharCount + this->m_rowSpacesCount >= this->m_targetLength - 1) || this->m_rowFirstWord == this->m_rowLastWord) break;
		else if(isLastRow && it == this->m_rowLastWord) break;
		else if(it == this->m_rowLastWord) it = this->m_rowFirstWord;
		else {
			
			*it += ' ';
			++this->m_rowSpacesCount;
			++it;
		}
	}

	for(auto it = this->m_rowFirstWord; it < this->m_rowLastWord + 1; ++it) formatted += *it;

	if(formatted.at(formatted.length() - 1) == '\n') this->m_formatted += formatted;
	else this->m_formatted += formatted + "\n";
}

void Paragraph::getWords() {

	this->m_words.clear();
	std::string newWord = "";

	for(char character : this->m_input) {

		if(character != ' ') { 
		
			if(character != '\t') newWord += character;
			else newWord += "    ";
		
		} else if(!newWord.empty()) {

			this->m_words.push_back(newWord);
			newWord.clear();
		}
	}

	if(!newWord.empty()) this->m_words.push_back(newWord);
}