//  Define the TextFile class here
#include "TextFile.h"
#include "AbstractFileVisitor.h"
#include <vector> 
#include <string> 
#include <iostream> 
using namespace std;

TextFile::TextFile(std::string inputName) : name(inputName) {
    std::vector<char> contents = {};
}

vector<char> TextFile::read() {
    /*
    for (int i = 0; i < getSize(); i++) {
        std::cout << contents[i]; 
    } */
    return contents;
}

int TextFile::write(std::vector<char> inputVector) {
    contents = inputVector;
    return 0;
}

int TextFile::append(std::vector<char> inputNew) {
    for (int i = 0; i < inputNew.size(); i++) {
        contents.push_back(inputNew[i]);
    }
    return 0;
}

unsigned int TextFile::getSize() {
    return contents.size();
}
std::string TextFile::getName() {
    return name;
}

void TextFile::accept(AbstractFileVisitor* file) {
    file->visit_TextFile(this);
}

AbstractFile* TextFile::clone(std::string file_name) {

    file_name.append(".txt");
    AbstractFile* text_file = new TextFile(file_name);
    vector<char> file_data = this->read();
    text_file->write(file_data);
    return text_file;
}