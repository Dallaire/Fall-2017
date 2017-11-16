#include <iostream>
#include <fstream>
#include <string>
#include "str_utils.h"

using namespace std;

int main(){
    string input;
    string iFileName;
    string oFileName;

    cout << "Please enter a file to read from \n";
    cin >> iFileName;

    ifstream iFile(iFileName, ifstream::in);

    if(!iFile){
  		cout << "ERROR: could not open file " << iFileName << "  ...exiting\n";
  		return(0);
    }

    cout << "Please enter a file to write to \n";
    cin >> oFileName;

    ofstream oFile(oFileName, ofstream::out);

    if(!oFile){
  		cout << "ERROR: could not open file " << oFileName << "  ...exiting\n";
  		return(0);
    }

    while(getline(iFile, input)){
  		oFile << StrUtils::toTitleCase(input) << "\n";
  	}

    iFile.close();
    oFile.close();
}
