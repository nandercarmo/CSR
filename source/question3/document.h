#ifndef MY_DOCUMENT_H
#define MY_DOCUMENT_H

#include <iostream>
#include <string>
#include <vector>

#include "paragraph.h"

class Document {
	
	public:

		Document(const std::string & input);
		std::string render() const;
		void setTargetLength(int);
		void format();

	private:

		std::vector<Paragraph> m_paragraphs;
		std::string m_input;
		std::string m_formatted;
		int m_targetLength;

		void getParagraphs();
}; 

#endif