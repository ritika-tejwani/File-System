#pragma once
#include "TouchCommand.h"
#include "RemoveCommand.h"
#include "LSCommand.h"
#include "DisplayCommand.h"
#include "MacroCommand.h"
#include "CopyCommand.h"
#include "CatCommand.h"
#include <map>

class CommandPrompt : public AbstractCommand {
private: 
	std::map<std::string, AbstractCommand*> command_map; 
	AbstractFileSystem* file_system; 
	AbstractFileFactory* file_factory; 

protected: 
	void listCommands(); 
	std::string prompt(); 

public:
	CommandPrompt(); 
	~CommandPrompt() = default; 
	int execute(std::string); 
	void displayInfo(); 
	void setFileSystem(AbstractFileSystem*); 
	void setFileFactory(AbstractFileFactory*); 
	int addCommand(std::string, AbstractCommand*); 
	int run();
};