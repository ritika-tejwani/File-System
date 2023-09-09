Studio 21 ReadMe.txt 

1. Ritika Tejwani, Ethan Fine, Josh Hart

2. It is important to declare a virtual destructor in the base class because it guarantees that the code calls the derived class destructor. Using a non-virtual destructor would result in undefined behavior, which is why we need to make sure the destructor is virtual. 

3. Using a concrete command, file system, and file factory object in our command prompt makes it flexible and reusable because we do not have to change the code of our command prompt, as its ability to take in any command/system/object means it can be used for a wide variety of code. Yes, the command prompt can be configured to use different file system implementations. 

4. For our test cases, we first created a dynamically allocated SimpleFileSystem, a SimpleFileFactory, and TouchCommand objects. We configured the TouchCommand object with the file system and file factory objects. We then created a variable of type CommandPrompt and configured it with the file system, file factory, and touch command objects. 

We then called run() on the command prompt object and test quitting, asking for help, asking for help on the touch command, and executing the touch command. 
Quit worked as expected. When we inputted “help”, it correctly listed all the commands available. And when we asked for help on the touch command, it displayed more information about the command. and then executing the touch command also worked. Then after quitting, we tried to access the file system and it worked and we verified that touch worked correctly by opening the file it created. 

AbstractFileSystem* file_system = new SimpleFileSystem();
AbstractFileFactory* file_factory = new SimpleFileFactory();
TouchCommand* touch_command = new TouchCommand(file_system, file_factory);

CommandPrompt cp;
cp.setFileSystem(file_system);
cp.setFileFactory(file_factory);

std::string file_name = “TextFile.text”;
touch_command.execute(file_name); 

int response = cp->run();

AbstractFile* text_file = file_system->openFile(file_name);
