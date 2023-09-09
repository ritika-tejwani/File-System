#pragma once
#include "AbstractCommand.h"

class EditDisplayCommand : public AbstractCommand {
private:
	AbstractFileSystem* file_system;
public:
	EditDisplayStrategy(AbstractFileSystem*);
	int execute(std::string);
	void displayInfo();
};