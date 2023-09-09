#include "RenameParsingStrategy.h"

using namespace std;

vector<string> RenameParsingStrategy::parse(string file_string) {
	vector<string> file_names;
	string file_1 = file_string.substr(0, file_string.find(" "));

	file_names.push_back(file_string);
	file_names.push_back(file_1);

	return file_names;
}