#pragma once
// studio 18 - file factory interface declared here

#include <string> 
#include "AbstractFile.h"

class AbstractFileFactory {
public: 
	virtual AbstractFile* createFile(std::string file_name) = 0;
};
