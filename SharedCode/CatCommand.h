#pragma once

#include "AbstractCommand.h"

class CatCommand : public AbstractCommand {
private: 
	AbstractFileSystem* file_system; 
public: 
	CatCommand(AbstractFileSystem*); 
	int execute(std::string); 
	void displayInfo(); 
};