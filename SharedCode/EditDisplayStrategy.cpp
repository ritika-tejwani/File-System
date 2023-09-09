#include "EditDisplayStrategy.h" 

#include <string>

using namespace std;

vector<string> EditDisplayStrategy::parse(string name) {
	if (name.find(" -d") != string::npos || name.find(" -a") != string::npos) {
		for (int i = 0; i < name.length(); i++) {
			if (name[i] == ' ') {
				name = name.substr(0, i);
			}
		}
	}

	vector<string> vector;
	if (name.find(" -a") != string::npos) {
		vector.push_back(name + " -a");
	}

	else {
		vector.push_back(name);
	}

	if (name.find(" -d") != string::npos) {
		vector.push_back(name + " -d");
	}

	else {
		vector.push_back(name);
	}

	return vector;
}
