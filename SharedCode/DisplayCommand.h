#pragma once
#include "AbstractCommand.h"
#include "BasicDisplayVisitor.h"

class DisplayCommand : public AbstractCommand {
private:
	AbstractFileSystem* file_system;
public:
	DisplayCommand(AbstractFileSystem*);
	int execute(std::string);
	void displayInfo();
};
