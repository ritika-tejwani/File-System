studio 18 answers here

1. Ethan Fine, Josh Hart, Ritika Tejwani

2. The factory method is a process that allows the programmer to create objects without clarifying its class beforehand. If we wanted to create a new file system, we would need to redefine createFile so that it is tailored to the new file system. 

3. Advantages:
	- It does not require the writing of as many methods when creating files.
	- Allows the creation of objects at runtime
   Disadvantages:
   	- Need to add more to the code when implementing a new file type.
	- Gets confusing when dealing with lots of files and complex code, for navigation may be difficult at large scales. 

4. The following are the tests we ran and their corresponding output: 
  - We first created a SimpleFileSystem and a SimpleFileFactory. We used the factory to create two files (one image and one text). This worked as expected and the files were created successfully. 

    AbstractFileSystem* system; 
    system = new SimpleFileSystem(); 
    AbstractFileFactory* factory;
    factory = new SimpleFileFactory();
    AbstractFile* img = factory->createFile("ImageFile.img");
    AbstractFile* txt = factory->createFile("TextFile.txt");
	
  - We then added the files to the SimpleFileSystem and opened the files. This worked as expected and the files were opened successfully. 
    system->addFile("ImageFile.img", img);
    system->addFile("TextFile.txt", txt); 
    system->openFile("ImageFile.img"); 
    system->openFile("TextFile.txt");
  
  - We created a vector<char> of a 3 by 3 image and wrote it to the image file. We then called the read function on the image file and it read the file successfully. 

    vector<char> v = { 'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', '3' }; 
    img->write(v); 
    img->read(); 

    Output: 
    X X X X X

 - We then created a vector<char> of the string "hi" and wrote it to the text file. We called the read function on the text file and it read the file successfully. 
 
    vector<char> v2 = {'h', 'i'};
    txt->write(v2); 
    txt->read(); 

    Output: 
    hi
    
  - We then created another vector<char> of the string "! test" and appended it to the text file. We called the read function on the text file and it read the file successfully. 
  
    vector<char> v3 = {'!', ' ', 't', 'e', 's', 't'};
    txt->append(v3); 
    txt->read(); 
    
    Output:
    hi! test

	- We then closed both the image and text files using the SimpleFileSystem. This worked as expected and the files were closed successfully. 
  
    system->closeFile(img);
    system->closeFile(txt);

5. all unit tests passed, 24/24
