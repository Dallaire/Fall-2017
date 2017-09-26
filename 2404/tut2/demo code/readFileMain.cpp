/* This program demonstrates reading strings from a text file
   To use the 
   istream& getline (istream&  is, string& str);
   method requires compilation consistent with c++11 
   not c++98 for example:
   g++ -g -Wall -std=c++11 main.cpp
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main(){
    string input; //input line read from file
    
	//create output file stream
	
	//char * fileName = "songtitles.txt"; //compatible with c++98
    string fileName = "songtitles.txt"; //requires -std=c++11 compile

	ifstream file(fileName, ifstream::in);  

	if(!file){
		cout << "ERROR: could not open file " << fileName << "  ...exiting\n";
		return(0);
	}

	
	cout << "CONTENTS OF: " << fileName << endl;
	cout << "=======================================\n";

  
	while(getline(file, input)){
		cout << input << endl;
	}

	file.close(); //fstream destructor will also close the file
	return(0);

}