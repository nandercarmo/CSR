#ifndef MY_FILE_H
#define MY_FILE_H

#include <string>

class File {

	public:

		File();
		~File();
		bool open(const std::string & fileName);
		char read();
		void close();
};

class FileRAII {

	private:

		File _file;

	public:

		FileRAII(const std::string & fileName) { this->_file.open(fileName); }
		~FileRAII() { this->_file.close(); }
		char read() { return this->_file.read(); }
};

#endif