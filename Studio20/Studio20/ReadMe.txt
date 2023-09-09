Studio 20 ReadMe.txt

1. Ritika Tejwani, Ethan Fine, Josh Hart

2. It is necessary to delete the pointer to the actual file in the PasswordProxy destructor because we create a new dynamically allocated variable. If we do not delete the pointer, then the variable will take up space in memory. We need to delete this pointer so that it does not occupy space. 

3. 
4. For out test cases, we first created a TextFile and then a password. We then created a PasswordProxy object with the file and password. We tried writing to, reading from, and displaying the file via the PasswordProxy object. All of these worked as expected. When we tried inputting an incorrect password, it would not let us access the file, as we wanted to. After that, we tried to display the file through the pass_proxy and we were able to read and print out the contents as expected. 

std::string file_name = “TextFile.txt";
AbstractFile* text_file = new TextFile(file_name);
std::string password = “hello”;
PasswordProxy* pass_proxy = new PasswordProxy(text_file, password);
stringstream ss_in;

std::vector<char> v = { 'h', 'i' };

ss_in << password + '\n' + password;
pass_proxy.write(v);

//this should not work 
string wrongPassword = “bye”;
ss_in << password + '\n' + wrongPassword;
pass_proxy.write(v) 

BasicDisplayVisitor* visitor = new BasicDisplayVisitor;
pass_proxy->accept(visitor); 
string s; 

vector<string> contents;
while (ss_out >> s) {
	contents.push_back(s);
}
for(int i = 0; i < contents.size(); i++){
	cout << contents[i]; 
}

5. all tests passed
