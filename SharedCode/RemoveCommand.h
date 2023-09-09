#pragma once
#include "AbstractCommand.h"

class RemoveCommand : public AbstractCommand {
private: 
	AbstractFileSystem* file_system; 
public: 
	RemoveCommand(AbstractFileSystem*);
	int execute(std::string); 
	void displayInfo(); 

};