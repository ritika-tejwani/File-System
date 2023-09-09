// define methods of SimpleFileSystem class here
#include "SimpleFileSystem.h"
#include "TextFile.h"
#include "ImageFile.h"

int SimpleFileSystem::addFile(std::string file_name, AbstractFile* file) {
	if (all_files.find(file_name) != all_files.end()) {
		cout << "Error: a file with the name " << file_name << " already exists" << endl;
		return error_fileAlreadyExists; 
	}
	if (file == nullptr) {
		cout << "Error: null pointer" << endl;
		return error_nullptr; 
	}
	all_files.insert(pair<string,AbstractFile*>(file_name,file)); 
	return Success;
}

/*
int SimpleFileSystem::createFile(std::string file_name) {
	if (all_files.find(file_name) != all_files.end()) {
		return error_fileAlreadyExists;
	}

	string text = "txt"; 
	string image = "img";

	if(strstr(file_name.c_str(), text.c_str()) != nullptr) {
		AbstractFile* text_file = new TextFile(file_name);
		all_files.insert({ file_name, text_file }); 
		return Success; 
	}
	if (strstr(file_name.c_str(), image.c_str()) != nullptr) {
		AbstractFile* image_file = new ImageFile(file_name);
		all_files.insert({file_name, image_file});
		return Success; 
	}

	return error_notTextorImageFile;
}
*/ 

AbstractFile* SimpleFileSystem::openFile(std::string file_name) {
	if ((all_files.find(file_name) != all_files.end())){
		if (all_files_open.find(all_files.find(file_name)->second) == all_files_open.end() ){
			all_files_open.insert(all_files.find(file_name)->second); 
			return all_files.find(file_name)->second;
		}
	}

	cout << "Error: null pointer" << endl;
	return nullptr; 
}

int SimpleFileSystem::closeFile(AbstractFile* file) {
	if (all_files_open.find(file) == all_files_open.end()) {
		cout << "Error: file can not be opened" << endl;
		return error_fileNotOpen; 
	}
	all_files_open.erase(file);
	return Success;
}

int SimpleFileSystem::deleteFile(std::string file_name) {
	if ((all_files.find(file_name) == all_files.end())) {
		cout << "Error: File could not be found" << endl;
		return error_fileDoesNotExist;
	}
	if (all_files_open.find(all_files.find(file_name)->second) != all_files_open.end()) {
		cout << "Error: Cannot delete file as the file is currently open" << endl; 
		return error_fileIsOpen; 
	}
	AbstractFile* pointer_to_file = all_files.find(file_name)->second; 
	all_files.erase(file_name);

	/*
	if (all_files.find(file_name) == all_files.end()) {
		cout << " removed " << endl;
	}
	*/
	 
	delete pointer_to_file; 
	return Success; 
}

std::set<string> SimpleFileSystem::getFileNames() {
	std::set<string> file_names; 
	map<string, AbstractFile*>::iterator it;
	
	for (it = all_files.begin(); it != all_files.end(); it++)
	{
		file_names.insert(it->first); 
	}

	return file_names; 
}
