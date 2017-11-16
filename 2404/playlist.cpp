#include <iostream>
#include <string>
using namespace std;

#include "playlist.h"

Playlist::Playlist(const string & aName){
	playlistName = aName;
}
Playlist::~Playlist(){
  cout << "~Playlist(void) "  << this << endl;
}

string Playlist::getPlaylistName(){return playlistName;}

string Playlist::toString()const {
	return playlistName;
}

ostream & operator<<(ostream & out, const Playlist & aPlaylist){
	out << aPlaylist.toString() << endl;
	return out;
}
