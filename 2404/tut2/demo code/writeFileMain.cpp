/* This program demonstrates writing strings to an output file
   To use the string class in ostream constructor requires 
   compilation consistent with c++11 not c++98 for example
   g++ -g -Wall -std=c++11 main.cpp
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    string input; //input line read from user
    
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
	cout << "quit to end" <<endl;

  
	while(true){
		getline(cin, input); //read line of user input
		if(input.compare("quit") == 0) break;
		else file << input << endl;
	}

	file.close(); //fstream destructor will also close the file
	return(0);

}