// Studio16.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "H:\Repositories\OOP-19\SharedCode\TextFile.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    AbstractFile* text_file;
    text_file = new TextFile("A few letters of the alphabet");
    vector<char> input = { 'a', 'b', 'c' };
    text_file->write(input);
    text_file->read();
    cout << endl;
    cout << text_file->getSize() << endl; 
    cout << text_file->getName() << endl;
    cout << endl;

    vector<char> inputNew = { 'd', 'e', 'f' }; 
    text_file->append(inputNew); 
    text_file->read(); 
    cout << endl;
    cout << text_file->getSize() << endl;
    return 0;
}


