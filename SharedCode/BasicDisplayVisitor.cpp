// definitions of basic display visitor here
#include "BasicDisplayVisitor.h"

#include <iostream>
#include <string>
#include <vector>
#include "Math.h"

using namespace std;

void BasicDisplayVisitor::visit_ImageFile(ImageFile* file) 
{
	vector<char> contents = file->read();
	int image_size = sqrt(contents.size()); 
	for (int row = image_size - 1; row >= 0; row--) {
		for (int col = 0; col < image_size; col++) {
			cout << contents[row * image_size + col];
		}
		cout << endl;
	}
}

void BasicDisplayVisitor::visit_TextFile(TextFile* file) {
	vector<char> contents = file->read();
	for (int i = 0; i < file->getSize(); i++) {
		std::cout << contents[i];
	}
}
