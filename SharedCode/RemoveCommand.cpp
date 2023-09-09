#include "RemoveCommand.h"
#include <iostream>

using namespace std;

RemoveCommand::RemoveCommand(AbstractFileSystem* system) {
	file_system = system; 
}

int RemoveCommand::execute(std::string file_name) {
	int return_val = file_system->deleteFile(file_name);
	if (return_val == error_fileDoesNotExist)
	{
		cout << "Error: file does not exist" << endl;
		return error_fileDoesNotExist;
	}
	else if (return_val == error_fileIsOpen)
	{
		cout << "Error: file is still open" << endl;
		return error_fileIsOpen;
	}
	else
	{
		return Success;
	}
}

void RemoveCommand::displayInfo() {
	cout << "use to remove a file. use by entering rm <filename>" << endl;
}