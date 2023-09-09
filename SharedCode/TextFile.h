#pragma once
#include <vector> 
#include <string>
#include "AbstractFile.h"
#include <algorithm>
#include <iostream>
#include <fstream> 
// TextFile declaration goes here

class TextFile : public AbstractFile {
private:
    std::vector<char> contents;
    std::string name;
public:
    TextFile(std::string inputName);
    std::vector<char> read();
    int write(std::vector<char> inputVector);
    int append(std::vector<char> inputNew);
    unsigned int getSize();
    std::string getName();
    void accept(AbstractFileVisitor* file);
    AbstractFile* clone(std::string);
};