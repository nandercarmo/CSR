#ifndef MY_PARAGRAPH_H
#define MY_PARAGRAPH_H

#include <iostream>
#include <string>
#include <vector>

#define DEBUG false

class Paragraph {
	
	public:

		Paragraph(const std::string &);
		std::string render() const;
		void setTargetLength(int);
		void format();

	private:

		std::string m_input;
		std::string m_formatted;
		std::vector<std::string> m_words;
		std::vector<std::string>::iterator m_rowFirstWord;
		std::vector<std::string>::iterator m_rowLastWord;
		int m_targetLength;
		int m_rowSpacesCount;
		int m_rowCharCount;

		void formatRow(bool);
		void getWords();
};

#endif