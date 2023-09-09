#include "CatCommand.h"
#include <iostream>

using namespace std;

CatCommand::CatCommand(AbstractFileSystem* system) {
	file_system = system;
}

int CatCommand::execute(string file_name) {
	string true_file_name;

	AbstractFile* new_file;
	if (file_name.find(' ') == string::npos)
	{
		new_file = file_system->openFile(file_name);
	}

	else {
		true_file_name = file_name.substr(0, file_name.find(' '));
		new_file = file_system->openFile(true_file_name);
	}

	if (new_file == nullptr) {
		cout << "Error: null pointer" << endl;
		return error_nullptr;
	}

	if (file_name.find(" -a") != string::npos) {
		true_file_name = file_name.substr(0, file_name.find(' '));
		//DISPLAY CURRENT CONTENTS OF THE FILE
		vector<char> file_contents = new_file->read();
		for (int i = 0; i < file_contents.size(); i++) {
			cout << file_contents[i];
		}
		cout << endl << "Please enter data, followed by either ':wq' to save and quit or ':q' to quit without saving" << endl;
		string word;
		vector<char> user_string;
		while (getline(cin, word))
		{
			if (word == ":wq") {
				user_string.pop_back();
				int return_value = new_file->append(user_string);
				if (return_value != Success) {
					return return_value;
				}
				file_system->closeFile(new_file);
				return Success;
			}

			else if (word == ":q") {
				file_system->closeFile(new_file);
				return Success;
			}

			else {
				for (int i = 0; i < word.length(); i++) {
					user_string.push_back(word[i]);
				}
				user_string.push_back('\n');
			}
		}
		return Success;
	}

	else {
		cout << endl << "Please enter data, followed by either ':wq' to save and quit or ':q' to quit without saving" << endl;
		string word;
		vector<char> user_string;
		while (getline(cin, word))
		{
			if (word == ":wq") {
				user_string.pop_back();
				int return_value = new_file->write(user_string);
				if (return_value != Success) {
					return return_value;
				}
				file_system->closeFile(new_file);
				return Success;
			}

			else if (word == ":q") {
				file_system->closeFile(new_file);
				return Success;
			}

			else {
				for (int i = 0; i < word.length(); i++) {
					user_string.push_back(word[i]);
				}
				user_string.push_back('\n');
			}
		}
		return Success;
	}
}

void CatCommand::displayInfo() {
	cout << "use to write to a command. use by entering cat <filename> [-a]" << endl;
}