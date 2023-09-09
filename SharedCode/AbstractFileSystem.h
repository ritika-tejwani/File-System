#pragma once
#include <set>
// declaration of the interface all file systems provide goes here

#include "AbstractFile.h"

class AbstractFileSystem {
public:
	virtual int addFile(std::string file_name, AbstractFile* file) = 0;
	//virtual int createFile(std::string file_name) = 0;
	virtual int deleteFile(std::string file_name) = 0;
	virtual AbstractFile* openFile(std::string file_name) = 0;
	virtual int closeFile(AbstractFile* file) = 0;
	virtual std::set<std::string> getFileNames() = 0; 
};
