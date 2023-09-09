Answer studio 16 questions here

1. Ethan Fine, Josh Hart, Ritika Tejwani 

2. An abstract class must contain at least one pure virtual function. So to declare an interface (abstract class), we must declare at least one pure virtual function. We would first create the abstract class as class AbstractClass{};  Then, within the brackets, we would have to declare at least one public pure virtual method (multiple pure virtual functions and static const data members can be delcared as needed). Then each derived class that inherits the interface (abstract class) will implement the pure virtual functions. 

3. a. TextFile inheriting publicly from AbstractFile is an example of interface inheritance. This is because it is public inheritance. 
   b. The member variables std::vector<char> that holds the file contents and std::string that holds the name of the file should be private member variables since we are only using them in the scope of a TextFile object. This follows the principle of encapsulation. 

4. We ran the test case of input {'a', 'b', 'c'} and when we read from the file it printed out abc as expected. Calling the getSize() function returned 3 as expected, and calling the getName() function returned the name of the text file ("A few letters of the alphabet") as expected. After that, we created a vector of chars called inputNew as {'d', 'e', 'f') and called append(inputNew) to the text file. Then when we read from the file, it outputted abcdef as expected. The getSize() function returned 6 as expected. 

5. To update main to interact with an arbitrary file type rather than a single concrete file type, we declared the text_file variable a pointer to an AbstractFile type rather than the TextFile type. By using a pointer to the abstract class/interface, it allows the variable to be any arbitrary file type. Then when we instantiate the variable, we can specify the file type.
	int main(int argc, char* argv[]) {
    		AbstractFile* text_file;
    		text_file = new TextFile("A few letters of the alphabet"); 
	}
   We re-ran the test cases from question 4 and got the same expected results. 

6. All test cases passed. 