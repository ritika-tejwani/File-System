// definition of ImageFile class here
#include "ImageFile.h"
#include "AbstractFileVisitor.h"
#include <iostream>

using namespace std; 

ImageFile::ImageFile(std::string name) {
	file_name = name;
	image_size = 0; 

}
vector<char> ImageFile::read() {
	/*
	for (int row = image_size-1; row >= 0; row--) {
		for (int col = 0; col < image_size; col++) {
			cout << contents[row * image_size + col]; 
		}
	}
	*/
	return contents;
}
int ImageFile::write(std::vector<char> inputVector) {
	image_size = inputVector[inputVector.size() - 1] - 48;
	if ((inputVector.size() - 1) != (image_size * image_size)) {
		contents.clear();
		image_size = 0;
		return error_size_mismatch;
	}
	for (int i = 0; i < inputVector.size() - 1; i++) {
		if (inputVector[i] == 'X' || inputVector[i] == ' ') {
			contents.push_back(inputVector[i]);
		}
		else {
			contents.clear();
			image_size = 0;
			return error_notXorspace;
		}
		 
	}
	
	return Success; 

}
int ImageFile::append(std::vector<char> inputNew) {
	return append_not_supported;
}
unsigned int ImageFile::getSize() {
	return contents.size();
}
std::string ImageFile::getName() {
	return file_name; 
}

void ImageFile::accept(AbstractFileVisitor* file) {
	file->visit_ImageFile(this);
}

AbstractFile* ImageFile::clone(std::string file_name) {
	file_name.append(".img");
	AbstractFile* image_file = new ImageFile(file_name);
	vector<char> file_data = this->read();
	image_file->write(file_data);
	return image_file;
}