#include "CopyCommand.h"
#include <iostream>

using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem* system) {
	file_system = system;
}

int CopyCommand::execute(string file_name) {
	//string true_file_name_1 = file_name.substr(0, file_name.find(" "));
	string true_file_name_2 = file_name.substr(file_name.find(" ") + 1);
	cout << true_file_name_2 << endl; 

	AbstractFile* new_file_1 = file_system->openFile(file_name.substr(0, file_name.find(" ")));

	if (new_file_1 == nullptr) {
		cout << "Error: null pointer" << endl;
		return error_nullptr;
	}

	AbstractFile* new_file_2 = new_file_1->clone(true_file_name_2);

	int return_value = file_system->addFile(new_file_2->getName(), new_file_2);
	if (return_value != Success)
	{
		file_system->closeFile(new_file_1);
		return copy_error;
	}

	file_system->closeFile(new_file_1);
	return Success;
}

void CopyCommand::displayInfo() {
	cout << "use to copy a file to another file. use by entering cp <original_file> <file_to_be_created>" << endl;
}