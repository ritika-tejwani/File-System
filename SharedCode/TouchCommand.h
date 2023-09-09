#pragma once
#include "AbstractCommand.h"
#include "PasswordProxy.h"

class TouchCommand : public AbstractCommand {
private:
	AbstractFileSystem* file_system; 
	AbstractFileFactory* file_factory;

public: 
	TouchCommand(AbstractFileSystem*, AbstractFileFactory*); 
	int execute(std::string); 
	void displayInfo(); 
	~TouchCommand() = default; 
};
