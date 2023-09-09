// Studio18.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "H:\Repositories\OOP-19\SharedCode\SimpleFileSystem.h"
#include "H:\Repositories\OOP-19\SharedCode\SimpleFileFactory.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	AbstractFileSystem* system;
	system = new SimpleFileSystem();

	AbstractFileFactory* factory;
	factory = new SimpleFileFactory();

	AbstractFile* img = factory->createFile("ImageFile.img");
	AbstractFile* txt = factory->createFile("TextFile.txt");

	system->addFile("ImageFile.img", img);
	system->addFile("TextFile.txt", txt);
	system->openFile("ImageFile.img");
	system->openFile("TextFile.txt");

	vector<char> v = { 'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', '3' };

	img->write(v);
	img->read();

	cout << endl;

	vector<char> v2 = { 'h', 'i' };

	txt->write(v2);
	txt->read();

	cout << endl;
	vector<char> v3 = { '!', ' ', 't', 'e', 's', 't' };
	txt->append(v3);
	txt->read();


	system->closeFile(img);
	system->closeFile(txt);

	return 0;

}