#include "TouchCommand.h"
#include <iostream>

using namespace std; 

TouchCommand::TouchCommand(AbstractFileSystem* system, AbstractFileFactory* factory) {
	file_system = system; 
	file_factory = factory; 
}

int TouchCommand::execute(string file_name) {
	string true_file_name;

	AbstractFile* new_file;
	if (file_name.find(' ') == string::npos)
	{
		new_file = file_factory->createFile(file_name);
		true_file_name = file_name;
	}

	else {
		true_file_name = file_name.substr(0, file_name.find(' '));
		new_file = file_factory->createFile(true_file_name);
	}

	if (new_file == nullptr) {
		cout << "Error: null pointer" << endl;
		return error_nullptr; 
	}
	if (file_name.find(" -p") == string::npos) {
		int add_success = file_system->addFile(true_file_name, new_file);
		if (add_success != 0) {
			delete new_file;
			cout << "Error: unable to add file" << endl;
			return add_success;
		}
		return Success;
	}
	if (file_name.find(" -p") != string::npos) {
		cout << "What would you like the file's password to be?" << endl;
		string password = "";
		cin >> password;
		AbstractFile* password_proxy_file = new PasswordProxy(new_file, password);
		int add_success = file_system->addFile(true_file_name, password_proxy_file);
		if (add_success != 0) {
			delete new_file;
			cout << "Error: unable to add file" << endl;
			return add_success;
		}
		return Success;
	}
}

void TouchCommand::displayInfo() {
	cout << "touch creates a file, touch can be invoked with the command : touch <filename>" << endl;
}