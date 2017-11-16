#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "songs.h"
#include "song.h"
	
Songs::Songs(){
}
Songs::~Songs(void){
	for(vector<Song*>::size_type i=0; i<collection.size(); i++)
		delete collection[i]; //delete songs in this container
}
vector<Song*>::iterator Songs::findPosition(Song & aSong){
	for (vector<Song*>::iterator it = collection.begin() ; it != collection.end(); ++it)
		if(*it == &aSong) return it;
	return collection.end();
}
Song * Songs::findByID(int anID){
	for (vector<Song*>::iterator it = collection.begin() ; it != collection.end(); ++it)
		if((*it)->getID() == anID) return *it;
	return NULL;
}
void Songs::add(Song & aSong){
	collection.push_back(&aSong);
}
void Songs::remove(Song & aSong){
	vector<Song*>::iterator index = findPosition(aSong);
	if(index != collection.end()) {
		Song * theSong = *index;
		collection.erase(index);
		delete theSong; //free the memory of theSong
	}
}
/*
void Songs::showOn(UI & view) const {
  view.printOutput("SONGS:");
  for(int i=0; i<collection.size(); i++)
       view.printOutput((*collection[i]).toString());	  
}
*/

void Songs::printOn(ostream & out) const {
  cout << "SONGS:" << endl;
  for(vector<Song*>::size_type i=0; i<collection.size(); i++)
       cout << (*collection[i]).toString() << endl;	  
}

ostream & operator<<(ostream & out, const Songs & songs){
  songs.printOn(out);
  return out;
}
