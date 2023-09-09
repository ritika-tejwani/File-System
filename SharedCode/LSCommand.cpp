
#include "LSCommand.h"
#include <iostream>
#include <set>
#include <iomanip> 
#include "MetadataDisplayVisitor.h"

using namespace std; 

LSCommand::LSCommand(AbstractFileSystem* system) {
	file_system = system; 
}

int LSCommand::execute(std::string input) {
	set<string> files = file_system->getFileNames();
	std::set<string>::iterator it;


	int longest_fileName = 0;
	for (it = files.begin(); it != files.end(); it++) {
		if ((*it).size() > longest_fileName) {
			longest_fileName = (*it).size();
		}

		if (input == "") {
			int count = 1;
			for (it = files.begin(); it != files.end(); it++) {
				std::cout << std::setw(longest_fileName);
				if (count % 2 != 0) {
					cout << *it;
					count++;
				}
				else {
					cout << " " << * it << endl;
					count++;
				}
			}
			cout << endl;
		}

		if (input == "-m") {
			for (it = files.begin(); it != files.end(); it++) {
				cout << setw(longest_fileName);
				MetadataDisplayVisitor* visitor = new MetadataDisplayVisitor();
				AbstractFile* file_name = file_system->openFile(*it);
				file_name->accept(visitor);
				delete visitor;
				file_system->closeFile(file_name);
			}
		}

		return Success;

	}
}

void LSCommand::displayInfo() {
	cout << "use to list all files. use by entering 'ls'" << endl;
}