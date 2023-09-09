Lab 5 Readme
Ritika Tejwani, Ethan Fine, Josh Hart

We split up the work almost completely evenly. We had multiple meetings amongst us three and had one person type on the computer while all three of us brainstormed and thought of ways to implement the code. There is not a section of the lab where someone did not do something / did the whole thing.

When building our project, we ran into a couple of errors. The first was a simple error as we just forgot to scope into std before using string. To fix this we just changed string to std::string. In addition, we were having linker errors as we had circular dependency between some of our header files. Another issue was when we created our EditDisplayStrategy, the file was not in the correct directory so it wasn't recognizing AbstractParsingStrategy and thus was not building. We corrected this by creating new files in SharedCode folder directly. 

For our test cases, we tried running the execute function on each command. 
- LSCommand: When running execute on this function, we had trouble with displaying the metadata and extracting them into strings. We realized the problem was the extraction part as we had all the metadata information on a new line each time. To fix this, we included all the information on one line and then a space between each component so that the extraction would work. 
- For CopyCommand, one of the issues we ran into was that it wasn’t cloning the file when using a password proxy. We realized that this was occurring because we didn’t have a clone function in the PasswordProxy class and instead just had it in the TextFile class. We had to add the function to PasswordProxy and then it worked. 
- RemoveCommand worked as expected on our first try. 
- User quit works as expected. 
- DisplayCommand: we had some issues with the display for an unformatted image, but then we fixed it by including a cout << endl; after the inner for loop when printing out the image contents. 
- EditDisplayStrategy: This command worked as expected on our first try. 
- CatCommand: We forgot to push back a new line character and we forgot to pop back at the start of wq so the tests were failing. We got help from a TA on this. 
