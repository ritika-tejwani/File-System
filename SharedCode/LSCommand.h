#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class LSCommand : public AbstractCommand {
private: 
	AbstractFileSystem* file_system; 
public: 
	LSCommand(AbstractFileSystem*);
	int execute(std::string input);
	void displayInfo(); 
};


