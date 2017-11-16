// Jacob Dallaire 100918375
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

class UI {
public:
  UI(); //Decided to make the interface an object
  void static read(string filename);
  void static log(string command, string filename="");
  void static help();
  void static parse(string input);
  void inittialize();
};
