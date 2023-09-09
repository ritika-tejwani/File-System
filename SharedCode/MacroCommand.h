#pragma once
#include "AbstractCommand.h"
#include <vector>
#include "AbstractParsingStrategy.h"

class MacroCommand : public AbstractCommand {
private:
	std::vector<AbstractCommand*> command_vector;
	AbstractParsingStrategy* parsing_strategy;
	AbstractFileSystem* file_system;
public:
	MacroCommand(AbstractFileSystem*);
	int execute(std::string);
	void displayInfo();
	void addCommand(AbstractCommand*);
	void setParseStrategy(AbstractParsingStrategy*);
};