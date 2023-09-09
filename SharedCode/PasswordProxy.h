#pragma once
#include "TextFile.h"
#include "ImageFile.h"
#include <string>


class PasswordProxy : public AbstractFile {
private:
	AbstractFile* file;
	std::string password;
public:
	PasswordProxy(AbstractFile* file, std::string input_password);
	~PasswordProxy();
	std::vector<char> read();
	int write(std::vector<char> inputVector);
	int append(std::vector<char>);
	unsigned int getSize();
	std::string getName();
	void accept(AbstractFileVisitor * file);
	AbstractFile* clone(std::string);
protected:
	virtual std::string passwordPrompt();
};