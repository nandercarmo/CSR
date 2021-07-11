#include "document.h"

Document::Document(const std::string & input) {

	this->m_input = input;
	this->m_formatted = "";
	this->m_targetLength = 35;

	this->format();
}

std::string Document::render() const {

	return this->m_formatted;
}

void Document::setTargetLength(int targetLength) {

	this->m_targetLength = targetLength;
}

void Document::format() {

	this->m_paragraphs.clear();
	this->getParagraphs();
	this->m_formatted.clear();

	for(auto paragraph : this->m_paragraphs) {
		
		paragraph.setTargetLength(this->m_targetLength);
		paragraph.format();

		this->m_formatted += paragraph.render();
	}
}

void Document::getParagraphs() {

	std::string paragraph = "";

	for(char character : this->m_input) {

		if(character != '\n') { 
		
			paragraph += character;
		
		} else {

			paragraph += character;
			this->m_paragraphs.push_back(Paragraph(paragraph));
			paragraph.clear();
		}
	}

	
	this->m_paragraphs.push_back(Paragraph(paragraph));
}