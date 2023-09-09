// studio 18 - simple file factory definitions

#include "SimpleFileFactory.h"
#include <string>
#include "ImageFile.h"
#include "TextFile.h"

using namespace std; 

AbstractFile* SimpleFileFactory::createFile(std::string file_name) {

	string text = "txt";
	string image = "img";

	if (strstr(file_name.c_str(), text.c_str()) != nullptr) {
		AbstractFile* text_file = new TextFile(file_name);
		return text_file; 
	}
	if (strstr(file_name.c_str(), image.c_str()) != nullptr) {
		AbstractFile* image_file = new ImageFile(file_name);
		return image_file; 
	}
	return nullptr; 

}
