#pragma once
#include "AbstractCommand.h"

class CopyCommand : public AbstractCommand {
private: 
	AbstractFileSystem* file_system; 
public: 
	CopyCommand(AbstractFileSystem*); 
	int execute(std::string); 
	void displayInfo(); 
};