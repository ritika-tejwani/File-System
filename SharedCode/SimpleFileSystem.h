#pragma once
// declaration of SimpleFileSystem class goes here
#include "AbstractFileSystem.h"
#include <map>
#include <set>
using namespace std; 

class SimpleFileSystem : public AbstractFileSystem {
private:
	std::map < std::string, AbstractFile*> all_files;
	std::set<AbstractFile*> all_files_open; 
public:
	int addFile(std::string file_name, AbstractFile* file); 
	//int createFile(std::string file_name); 
	int deleteFile(std::string file_name); 
	AbstractFile* openFile(std::string file_name); 
	int closeFile(AbstractFile* file); 
	std::set<string> getFileNames(); 

};
