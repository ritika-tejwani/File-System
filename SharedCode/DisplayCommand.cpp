#include "DisplayCommand.h"
#include <iostream>

using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem* system) {
	file_system = system;
}

int DisplayCommand::execute(string file_name) {
	string true_file_name;

	AbstractFile* new_file;
	if (file_name.find(" ") == string::npos)
	{
		new_file = file_system->openFile(file_name);
	}

	else {
		//true_file_name = file_name.substr(0, file_name.find(" "));
		new_file = file_system->openFile(file_name.substr(0, file_name.find(" ")));
	}

	if (new_file == nullptr) {
		cout << "Error: null pointer" << endl;
		return error_nullptr;
	}

	if (file_name.find(" -d") != string::npos) {
		vector<char> file_contents = new_file->read();
		for (int i = 0; i < file_contents.size(); i++) {
			cout << file_contents[i];
		}
		cout << endl;
		file_system->closeFile(new_file);
		return Success;
	}

	if (file_name.find(" ") == string::npos) {
		AbstractFileVisitor* visitor = new BasicDisplayVisitor();
		new_file->accept(visitor);
		delete visitor;
		file_system->closeFile(new_file);
		return Success;
	}

	return Success;
}

void DisplayCommand::displayInfo() {
	cout << "use to display a file's information. use by entering ds <filename> [-d] (-d formats the output)" << endl;
}