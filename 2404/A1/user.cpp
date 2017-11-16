#include <iostream>
#include <string>
using namespace std;

#include "user.h"

User::User(const string anUserID, const string aName){
	userID = anUserID;
	name = aName
}
Song::~User(){
	cout << "~User(void) "  << this << endl;
}
string User::getID(){return userID;}


vector<Playlist*>::iterator User::findPosition(Playlist & aPlaylist){
	for (vector<Playlist*>::iterator it = playlists.begin() ; it != playlists.end(); ++it)
		if(*it == &aPlaylist) return it;
	return playlists.end();
}

User * User::findByName(string playlistName){
	for (vector<Playlist*>::iterator it = playlists.begin() ; it != playlists.end(); ++it)
		if((*it)->getName() == playlistName) return *it;
	return NULL;
}

string User::addPlaylist(string playlistName){
	 playlists.push_back(new Playlist(playlistName));
	 string message;
	 message += "Created empty playlist " + playlistName + " for user: " + userID + "\n";
	 return message;
}

string User::deletePlaylist(string playlistName){
	vector<Playlist*>::iterator index = findPosition(findByName(playlistName));
	if(index != playlists.end()) {
		Playlist * thePlaylist = *index;
		playlists.erase(index);
		delete thePlaylist; //free the memory of thePlaylist
	}
  string message;
  message += "Deleted playlist " + playlistName + " for user: " + userID + "\n";
  return message;
}

string User::showPlaylists(){
	string message;
  message += "Displaying all of user's playlists \n";
  for(vector<Playlist*>::size_type i=0; i<playlists.size(); i++)
       message+= (*playlists[i]).toString() << "\n";
  return message;
}

string User::toString()const {
	return userID + " " + name;
}

ostream & operator<<(ostream & out, const User & aUser){
	out << aUser.toString() << endl;
	return out;
}
