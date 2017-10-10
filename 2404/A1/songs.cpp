// Jacob Dallaire 100918375
#include <string>
#include <iostream>
#include "songs.h"
#include "str_util.h"
using namespace std;

string Songs::addSong(string id, string title, string composer){
  string titleCased = StrUtil::toTitleCase(title);
  string message;
  message += "Added " + titleCased + "by " + composer + "to songs collection" + "\n";
  return message;
}

string Songs::deleteSong(string songid){
  string message;
  message += "Deleted song with id: " + songid + "\n";
  return message;
}

string Songs::show(){
  string message;
  message += "Displaying all songs \n";
  return message;
}
