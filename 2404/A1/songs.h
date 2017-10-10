// Jacob Dallaire 100918375
#include <string>
#include <iostream>
using namespace std;

class Songs{
public:
  static string addSong(string id, string title, string composer);
  static string deleteSong(string songid);
  static string show();
};
