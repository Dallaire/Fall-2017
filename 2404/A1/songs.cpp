// Jacob Dallaire 100918375
#include <string>
#include <iostream>
#include "songs.h"
#include "str_util.h"
using namespace std;

Songs::Songs(){
}
Songs::~Songs(void){
	for(vector<Song*>::size_type i=0; i<library.size(); i++)
		delete library[i]; //delete songs in this container
}
vector<Song*>::iterator Songs::findPosition(Song & aSong){
	for (vector<Song*>::iterator it = library.begin() ; it != library.end(); ++it)
		if(*it == &aSong) return it;
	return library.end();
}
Song * Songs::findByID(int anID){
	for (vector<Song*>::iterator it = library.begin() ; it != library.end(); ++it)
		if((*it)->getID() == anID) return *it;
	return NULL;
}

string Songs::addSong(int id, string title, string composer){
  string titleCased = StrUtil::toTitleCase(title);
  library.push_back(new Song(title,composer,id));
  string message;
  message += "Added " + titleCased + "by " + composer + "to songs collection" + "\n";
  return message;
}

string Songs::deleteSong(int songid){
  vector<Song*>::iterator index = findPosition(findByID(songid));
	if(index != library.end()) {
		Song * theSong = *index;
		library.erase(index);
		delete theSong; //free the memory of theSong
	}
  string message;
  message += "Deleted song with id: " + songid + "\n";
  return message;
}

string Songs::show(){
  string message;
  message += "Displaying all songs \n";
  for(vector<Song*>::size_type i=0; i<library.size(); i++)
       message+= (*library[i]).toString() << "\n";
  return message;
}
