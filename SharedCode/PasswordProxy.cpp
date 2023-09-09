#include "PasswordProxy.h"
#include <iostream>

using namespace std;

PasswordProxy::PasswordProxy(AbstractFile*input_file, string input_password)
{
	password = input_password;
	file = input_file;
}
PasswordProxy::~PasswordProxy()
{
	delete file;
}

string PasswordProxy::passwordPrompt()
{
	string password;
	cout << "What is your password" << endl;
	cin >> password;
	return password;
}

std::vector<char> PasswordProxy::read()
{
	vector<char> empty;
	string pw;
	pw = passwordPrompt();
	if (pw == password)
	{
		return file->read();
	}
	return empty;
}

int PasswordProxy::write(std::vector<char> inputVector)
{
	vector<char> empty = {};
	string input_pw;
	input_pw = passwordPrompt();
	if (input_pw == password)
	{
		return file->write(inputVector);
	}
	
	file->write(empty);

	return wrong_password;

	
}

int PasswordProxy::append(std::vector<char> inputVector)
{
	string input_pw = passwordPrompt();
	if (input_pw == password)
	{
		return file->append(inputVector);
	}

	return wrong_password;
}
unsigned int PasswordProxy::getSize()
{
	return file->getSize();
}
std::string  PasswordProxy::getName()
{
	return file->getName();
}
void PasswordProxy::accept(AbstractFileVisitor* input_file)
{
	string input_pw = passwordPrompt();
	if (input_pw == password)
	{
		file->accept(input_file);
	}
}

AbstractFile* PasswordProxy::clone(string new_file_name) {
	AbstractFile* new_file = file->clone(new_file_name);
	return new PasswordProxy(new_file, password);
}