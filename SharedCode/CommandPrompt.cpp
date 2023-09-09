#include "CommandPrompt.h"
#include <iostream>
#include <sstream>
#include "LSCommand.h"
using namespace std; 

void CommandPrompt::listCommands() {
	std::map<string, AbstractCommand*>::iterator it;

	for (it = command_map.begin(); it != command_map.end(); it++)
	{
		cout << it->first << endl; 
	}
	
}
std::string CommandPrompt::prompt() {
	string input;
	cout << endl; 
	cout << "Enter a command, 'q' to quit, 'help' for a list of commands, 'help <command name>' for details about a specific command, or 'ls' to see a list of all the files." << endl;
	cout << "$   "; 
	std::getline(std::cin, input);
	return input; 
}

CommandPrompt::CommandPrompt() {
	file_factory = nullptr; 
	file_system = nullptr; 
}
	
void CommandPrompt::setFileSystem(AbstractFileSystem* system) {
	file_system = system; 
}
void CommandPrompt::setFileFactory(AbstractFileFactory* factory) {
	file_factory = factory; 
}
int CommandPrompt::addCommand(std::string command_name, AbstractCommand* command) {
	if (command == nullptr) {
		return error_nullptr;
	}
	try {
		command_map.insert({ command_name, command });
	}
	catch (...){
		return failure_mapInsertion; 
	}
	
	return Success; 
}
int CommandPrompt::run() {
	while (1) {
		string input_command = prompt();
		if (input_command == "q") {
			cout << "user quit" << endl; 
			return user_quit;
		}
		if (input_command == "help") {
			listCommands();
		}
		
		bool one_word = true;
		for (int i = 0; i < input_command.size(); i++) {
			if (input_command[i] == ' ') {
				one_word = false;
			}
		}
		if (one_word && input_command != "help") {

			if (command_map.find(input_command) == command_map.end()) {
				cout << "The command did not exist." << endl;
			}
			else {
				int run_command = command_map.find(input_command)->second->execute("");
				if (run_command != 0) {
					cout << "The command failed" << endl;
				}
			}

		}
		if (!one_word) {
			string firstWord; 
			istringstream iss(input_command); 
			iss >> firstWord; 

			string secondWord;
			iss >> secondWord;

			if (firstWord == "help") {
				if (command_map.find(secondWord) == command_map.end()) {
					cout << "The command does not exist" << endl; 
				}
				else {
					command_map.find(secondWord)->second->displayInfo(); 
				}
			}
			else {
				if (command_map.find(firstWord) == command_map.end()) {
					cout << "The command did not exist." << endl;
				}
				else {
					int run_command = command_map.find(firstWord)->second->execute(input_command.substr(firstWord.length() + 1));
					if (run_command != 0) {
						cout << "The command failed" << endl;
					}
				}
			}
		}


	}
	
}

int CommandPrompt::execute(std::string) {
	return Success; 
}

void CommandPrompt::displayInfo() {
	cout << "you can access all your commands through here" << endl;
}