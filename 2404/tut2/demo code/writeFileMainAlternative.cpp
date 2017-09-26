/* 
   This program demonstrates writing strings to an output file
   To use the string class in ostream constructor requires 
   compilation consistent with c++11 not c++98 for example
   g++ -g -Wall -std=c++11 main.cpp
   
   This example also shows an approach to reading input that
   generates a lot of debate.
   The program is expecting input in a very specific format
   and "blindly" reads it into variables. (What if the input is not
   in the correct format.) 
   
   The same approach is used to read files. Specifically the file
   format is assumed to be correct and the program "blindly" reads it
   into variables.
   
   Many feel this approach is inherently unsafe. That a program is
   better off reading an entire line of input and then going about
   scrutinizing and digesting the input.
   
   Many books show the example here as "how to do input" but many feel this is an example of "how NOT to do input".  
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	
	string firstName;
	string lastName;
	string phoneNumber;
    
	//create output file stream
	
	//char * fileName = "phoneData.txt"; //compatible with c++98
    string fileName = "phoneData.txt"; //requires -std=c++11 compile

	ofstream file(fileName, ofstream::out);  

	if(!file){
		cout << "ERROR: could not open file " << fileName << "  ...exiting\n";
		return(0);
	}

	//Run User Interface
	cout << "Please enter names and phone numbers one line at time, for example\n";
	cout << "John Smith 234-7689\n";
	cout << "CNTL-D to end" <<endl;

  
	while(cin >> firstName >> lastName >> phoneNumber){
		file << firstName << " " 
		     <<  lastName << " " << phoneNumber << endl;
	}

	file.close(); //fstream destructor will also close the file
	return(0);

}