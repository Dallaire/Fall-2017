/* * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                   */
/*  Program:  MyTunes Music Player                   */
/*  Author:   Louis Nel                              */
/*  Date:     21-SEP-2017                            */
/*                                                   */
/*  (c) 2017 Louis Nel                               */
/*  All rights reserved.  Distribution and           */
/*  reposting, in part or in whole, requires         */
/*  written consent of the author.                   */
/*                                                   */
/*  COMP 2404 students may reuse this content for    */
/*  their course assignments without seeking consent */
/* * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <string>
using namespace std;

#include "playlist.h"

Playlist::Playlist(const string & aPlaylistName){
	cout << "Playlist(string&)" << endl;
	name = aPlaylistName;
}
Playlist::Playlist(const Playlist & aPlaylist){
	cout << "Playlist(const Playlist & aPlaylist)" << endl;
	cout << "ERROR: Playlist(const Playlist & aPlaylist) --should never run" << endl;
}

Playlist::~Playlist(){
	cout << "~Playlist(void)" << endl;
}
//int Playlist::getID(){return -1;}
string Playlist::getID(){return name;}

map<int, Track*> & Playlist::getTracks(){return tracks;}

map<int, Track*>::iterator Playlist::findPosition(Track & aTrack){
	for (map<int, Track*>::iterator itr = tracks.begin() ; itr != tracks.end(); ++itr)
		if(*itr->second == &aTrack) return itr;
	return tracks.end();
}

void Playlist::addTrack(Track & aTrack){
	//add track if it does not already exist
	map<int, Track*>::iterator itr = findPosition(aTrack);
	if(itr == tracks.end()) {
		tracks.insert({aTrack.getID(),aTrack});
	}
}

void Playlist::removeTrack(Track & aTrack){
	map<int, Track*>::iterator itr = findPosition(aTrack);
	if(itr != tracks.end()) {
		tracks.erase(itr->first);
	}
}

string Playlist::toString()const {
	string indent = "     ";
	string s;
	s.append(name);
	s.append("\n");
	s.append(indent + indent + "Playlist Tracks:\n");
	for (std::map<int,Track>::iterator it = collection.begin(); it != collection.end(); ++it){
		   s.append(indent + indent + tracks->second.toString() + "\n");
	}

	return s;
}

ostream & operator<<(ostream & out, const Playlist & aPlaylist){
	out << aPlaylist.toString() << endl;
	return out;
}
