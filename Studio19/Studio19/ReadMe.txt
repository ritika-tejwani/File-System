studio 19 answers here
1. Ritika Tejwani, Ethan Fine, Josh Hart

2. The following is the code we used in our main method: We first created a text file, wrote a vector<char> to the text_file, and read from the file. When we read from the file, we had to create a loop to print out the contents since the read method now just returns the contents. This returned the correct character : "test". Then we appended the text file with a vector<char> of "hi". Then, again, we read from the file and printed out the contents, which returned "testhi" correctly. Overall, we stored the files' contents into a local variable, made edits to the file’s contents, and rewrote the file with the modified contents. Everything worked as expected. Our test case was a text file in this example, but we also tried this with an image file and instead of append, just rewrote to the file. 

std::string file_name = "SampleText.txt";
unsigned int fileSize = 0;
TextFile text_file(file_name);
std::vector<char> v = { 't', 'e', 's', 't'};
text_file.write(v)
std::vector<char> contents = text_file.read();
for (int i = 0; i < contents.size(); i++) {
	cout << contents[i] << endl; 
}
std::vector<char> extra = { 'h', 'i'}; 
text_file.append(extra); 
std::vector<char> contents_appended = text_file.read();
for (int i = 0; i < contents_appended.size(); i++) {
	cout << contents_appended[i] << endl; 
}

std::vector<char> rewrite = { 'n', 'e', 'w'}; 
text_file.write(rewrite); 
std::vector<char> contents_new = text_file.read();
for (int i = 0; i < contents_new.size(); i++) {
				cout << contents_new[i] << endl; 
}

3. First, you need to create an accept() method. Next, you need to create a visitor base class with a visit() method. Next, create a visitor derived class for each class you want to be able to visit. Lastly, create visitor objects, where accept() can be called. 

4. Delegation is a process that allows us to use a class member as if it were a member of a different class. It is useful because we
can call methods and use properties from different classes. It is similar to inheritance, but is more efficient. We use delegation in
BasicDisplayVisitor and MetadataDisplayVisitor because we can call functions from the AbstractFileVisitor file. 

5. Using the visitor pattern may have the drawback that, when there are a lot of unique visitors, one small change would require
that we change all of the visitors in the visitor pattern. 
