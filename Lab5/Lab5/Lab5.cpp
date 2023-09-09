// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "../../SharedCode/CommandPrompt.h"
#include "../../SharedCode/LSCommand.h"
#include "../../SharedCode/RemoveCommand.h"
#include "../../SharedCode/CopyCommand.h"
#include "../../SharedCode/DisplayCommand.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/SimpleFileFactory.h"
#include <sstream>
#include "../../SharedCode/RenameParsingStrategy.h"
#include "../../SharedCode/EditDisplayStrategy.h"

int main()
{
	AbstractFileSystem* sfs = new SimpleFileSystem();
	AbstractFileFactory* sff = new SimpleFileFactory();

	AbstractCommand* cat_cmd = new CatCommand(sfs);
	AbstractCommand* copy_cmd = new CopyCommand(sfs);
	AbstractCommand* display_cmd = new DisplayCommand(sfs);
	AbstractCommand* ls_cmd = new LSCommand(sfs);
	AbstractCommand* remove_cmd = new RemoveCommand(sfs);
	AbstractCommand* touch_cmd = new TouchCommand(sfs, sff);
	

	AbstractParsingStrategy* rps = new RenameParsingStrategy();

	MacroCommand* rn_cmd = new MacroCommand(sfs);
	rn_cmd->setParseStrategy(rps);
	rn_cmd->addCommand(copy_cmd);
	rn_cmd->addCommand(remove_cmd);

	AbstractParsingStrategy* editDisplay = new EditDisplayStrategy();
	MacroCommand* edit_display_cmd = new MacroCommand(sfs);
	edit_display_cmd->addCommand(cat_cmd);
	edit_display_cmd->addCommand(display_cmd);
	edit_display_cmd->setParseStrategy(editDisplay);


	CommandPrompt cmd_prompt = CommandPrompt();
	cmd_prompt.addCommand("cat", cat_cmd);
	cmd_prompt.addCommand("cp", copy_cmd);
	cmd_prompt.addCommand("ds", display_cmd);
	cmd_prompt.addCommand("ls", ls_cmd);
	cmd_prompt.addCommand("rn", rn_cmd);
	cmd_prompt.addCommand("rm", remove_cmd);
	cmd_prompt.addCommand("touch", touch_cmd);
	cmd_prompt.addCommand("catds", edit_display_cmd);
	
	AbstractFile* file1 = new TextFile("text1.txt");
	sfs->addFile("text1.txt", file1);

	cmd_prompt.run();

	return Success;
}