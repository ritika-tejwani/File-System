#include "MacroCommand.h"
#include "AbstractParsingStrategy.h"
#include "AbstractCommand.h"
#include <iostream>

using namespace std;

MacroCommand::MacroCommand(AbstractFileSystem* system) {
	parsing_strategy = nullptr;
	file_system = system;
}

int MacroCommand::execute(string file_name) {
	//vector<string> inputs = parsing_strategy->parse(file_name);
	vector<string> inputs = parsing_strategy->parse(file_name); 
	if (inputs.size() != command_vector.size()) {
		return wrong_num_commands;
	}
	for (int i = 0; i < command_vector.size(); i++) {
		int return_value = command_vector[i]->execute(inputs[i]);
		if (return_value != Success) {
			cout << "Error: unable to execute on a file" << endl;
			return return_value;
		}
	}
	return Success;
}

void MacroCommand::displayInfo() {
	cout << "this is how to use each command:" << endl;
	for (int i = 0; i < command_vector.size(); i++) {
		command_vector[i]->displayInfo();
	}
}

void MacroCommand::addCommand(AbstractCommand* command) {
	command_vector.push_back(command);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* strategy) {
	this->parsing_strategy = strategy;
}