#include <iostream>
#include <string>
#include "person.h"

using namespace std;
int main(void){
  string input;

  cout << "Hello World\n";

  Person lou("Lou", "ldnel@scs.carleton.ca", "613 520-2600 ex4335");
  Person dan("Dan", "dan@hotmail.com", "613 555-1234");

  lou.printOn(cout);
  cout << "\n";
  dan.printOn(cout);

  //keep console open until user presses a key
  cout << "\n\n" << "Press any key to continue";
  getline(cin, input);
  return 0;
}
