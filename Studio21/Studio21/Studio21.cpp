// Studio21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../../SharedCode/CommandPrompt.h"
#include "../../SharedCode/TouchCommand.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/SimpleFileFactory.h"
#include <sstream>

int main()
{
	AbstractFileSystem* file_system = new SimpleFileSystem();
	AbstractFileFactory* file_factory = new SimpleFileFactory();
	TouchCommand* touch_command = new TouchCommand(file_system, file_factory);

	CommandPrompt cp;
	cp.setFileSystem(file_system);
	cp.setFileFactory(file_factory);

	std::string file_name = "TextFile.text";
	touch_command->execute(file_name);

	int response = cp.run();

	AbstractFile* text_file = file_system->openFile(file_name);
}

