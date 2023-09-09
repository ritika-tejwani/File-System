// Studio17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "H:\Repositories\OOP-19\SharedCode\ImageFile.h"
#include "H:\Repositories\OOP-19\SharedCode\SimpleFileSystem.h"
#include <iostream>


using namespace std;


int main(int argc, char* argv[])
{
	/*
	
      string file_name = "ImageFile.img";
      ImageFile image_file(file_name);
      cout << image_file.getName() << endl; 
      cout << image_file.getSize() << endl;
 
      vector<char> image_vector = { 'X', ' ', 'X', ' ', 'X', ' ', 'X',' ', 'X', '3' };
      image_file.write(image_vector); 

      image_file.read(); 
 
      vector<char> image_vector = { 'X', ' ', 'X', ' ', 'X', ' ', 'X',' ', 'X', '10' };
      image_file.write(image_vector);
      //should give an ERROR
      
      vector<char> image_vector = { 'X', ' ', 'B', ' ', 'X', '!', 'X',' ', 'X', '10' };
      image_file.write(image_vector);
      //should give an ERROR
       
      vector<char> append_vector = { 'X', ' ', 'X', ' ', '2' };
      image_file.append(image_vector);
      //should give an ERROR
	
	*/

	SimpleFileSystem sfs;
	// check using add -- expect to see the same file returned
	AbstractFile* img = new ImageFile("FileName.img");
	cout << sfs.addFile(img->getName(), img) << endl; 
	AbstractFile* res1 = sfs.openFile(img->getName());
	bool sameAddress = &(*img) == &(*res1);
	cout << sameAddress << endl; 

	// check using create -- a quick check to see that create adds successfully and open finds the file by returning a pointer that  is not null
	sfs.createFile("FileName.txt");
	AbstractFile* res2 = sfs.openFile("FileName.txt");
	bool nullCheck = res2 == nullptr;
	cout << nullCheck << endl;

	return 0;
}

