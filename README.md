# Studios 16-21 and Lab 5 Descriptions 

This File System project was part of a class I took at WashU: CSE 332 Object-Oriented Programming in C++. I worked with two of my classmates on this project.

● Studio 16: A filesystem may hold many different file types (text file, executable file, image files, etc.). In studio 16, we created an abstract base class that declares the interface shared by all file types and then implemented this interface to create a class representing a text file. Topics covered: interface inheritance

● Studio 17: In this studio we implemented a second concrete file type, an image file. We also created an abstract base class declaring the interface of a filesystem and implemented this interface in a class representing a simple filesystem implementation. Topics covered: Programming to an interface

● Studio 18: In this studio, we created a new family of classes responsible for creating new files based on the file’s extension (“.txt” for example). We implemented the abstract factory pattern to accomplish this while allowing your code to be easily extended to support new file types in the future. Topics covered: single responsibility principle, abstract factory pattern

● Studio 19: In this studio, we used the visitor pattern to display the contents of files in unique ways. The “visitors” we created can be used to display different information about files or the files contents in different formats. A new “visitor” can be implemented for each new format a file should be displayed in. Topics covered: visitor pattern, delegation

● Studio 20: In this studio, we added functionality for password protected files. We used the proxy pattern to accomplish this. Topics covered: Proxy pattern, request forwarding, object composition

● Studio 21: In this studio, we implemented the command pattern to create a command prompt that listens for user input and executes a “command” based on the command issued by the user. We implemented the “touch” command, which creates a new file and adds it to the file system. Topics covered: Command pattern

● Lab 5: In lab 5, we implemented several more “commands” using a couple of different design patterns. At the end of lab 5, we were able to interact with our filesystem implementation by interactively executing commands to do things like create files and password protected files, write to files, read from files, copy files, delete files, etc.
