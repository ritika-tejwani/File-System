Answer the studio 17 questions here.

1. Ethan Fine, Josh Hart, Ritika Tejwani 

2. To test the functionality of your ImageFile class, we ran the following tests: 
  - We created an object of the type ImageFile and just checked that we could access the file name and file size. This worked as   expected: 
      string file_name = "ImageFile.img";
      ImageFile image_file(file_name);
      cout << image_file.getName() << endl; 
      cout << image_file.getSize() << endl;
      
      Output: 
      ImageFile.img
      0
      
  - We then extended this code and tried to write to the file. This returned a success as expected. 
      vector<char> image_vector = { 'X', ' ', 'X', ' ', 'X', ' ', 'X',' ', 'X', '3' };
      image_file.write(image_vector); 
      
  - We then extended the code and tried to read the file and it returned as expected. 
      image_file.read(); 
      
      Output: 
      X X X X X
      
Error Tests: 
  - We changed image_vector to be a vector of size 10 (in total) but change the last char to 5. And then we tried to write to the file and it returned a size mismatch error as expected because the vector is for a 3 by 3 but the last char says it's size 5. 
      vector<char> image_vector = { 'X', ' ', 'X', ' ', 'X', ' ', 'X',' ', 'X', '10' };
      image_file.write(image_vector);
      -> ERROR
      
  - We changed the image vector to contain a char that's not 'X' or ' ' and tried to write to the file. It returned the appropriate error as expected.
      vector<char> image_vector = { 'X', ' ', 'B', ' ', 'X', '!', 'X',' ', 'X', '10' };
      image_file.write(image_vector);
      -> ERROR
      
  - We tried to append a vector but it returned the appropriate error as you can't append to an image file. 
      vector<char> append_vector = { 'X', ' ', 'X', ' ', '2' };
      image_file.append(image_vector);
      -> ERROR
  
  
3. The biggest advantage of programming a client to use an interface rather than a concrete class is that it prevents having to re-write code for each class that shares some common behavior (methods) or members (variables). When we have an interface and different classes inherit that same interface, it allows us to put all the shared behaviors in the interface and can be accessed by each class. At the same time, the classes can still be different from each other in the other ways. So we can group common behaviors and members exhibited by several non-related classes of objects in an efficient way. 

4. To be able to create an object of a new concrete file type, we would have to add code within the createFile() method. The createFile() method currently only works for .txt and .img files and has to check the file name, then based on which file type it is, creates an object of that new concrete file type. Other than this method, the SimpleFileSystem class is entirely coded to use the AbstractFile interface. The createFile() method depends on understanding how to construct objects of each concrete file type. 

5. All unit tests passed, 25/25

