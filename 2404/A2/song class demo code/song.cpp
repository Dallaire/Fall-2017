#include <iostream>
#include <string>
using namespace std;

#include "song.h"
	
Song::Song(const string & aTitle, const string & aComposer, const int anID){
	cout << "Song(string&, string&, int) " << this << endl;
	title = aTitle;
	composer = aComposer;
	id = anID;
}
Song::~Song(){
	cout << "~Song(void) "  << this << endl;
}
int Song::getID(){return id;}

string Song::toString()const {
	return to_string(id) + " " + title + " " + composer;
}

ostream & operator<<(ostream & out, const Song & aSong){
	out << aSong.toString() << endl;
	return out;
}
