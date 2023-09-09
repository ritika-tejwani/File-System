#pragma once
// Image file class declaration here
#include "AbstractFile.h"


class ImageFile : public AbstractFile {
private: 
	std::string file_name; 
	std::vector<char> contents; 
	char image_size; 

public: 
	ImageFile(std::string name); 
	std::vector<char> read();
	int write(std::vector<char> inputVector);
	int append(std::vector<char> inputNew);
	unsigned int getSize();
	std::string getName();
	void accept(AbstractFileVisitor* file);
	AbstractFile* clone(std::string);

};
