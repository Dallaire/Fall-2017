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

#include "recording.h"

Recording::Recording(const string & aTitle,
           const string & anArtist,
           const string & aProducer,
           const string & aYear,
		   const int anID){
	cout << "Recording(string&, string&, String&, String&, int)" << endl;
	title = aTitle;
	artist = anArtist;
	producer = aProducer;
	year = aYear;
	id = anID;
	tracks = vector<Track*>(MAX_NUMBER_OF_TRACKS, NULL);
}
Recording::Recording(const Recording & aRecording){
	cout << "Recording(const Recording & aRecording)" << endl;
	cout << "ERROR: Recording(const Recording & aRecording) --should never run" << endl;
}
Recording::~Recording(){
	cout << "~Recording(void)" << endl;
}
int Recording::getID(){return id;}
map<int, Track*> & Recording::getTracks(){return tracks;}

map<int, Track*>::iterator Recording::findPosition(Track & aTrack){
	for (map<int, Track*>::iterator it = tracks.begin() ; it != tracks.end(); ++it)
		if(*it->second == &aTrack) return it;
	return tracks.end();
}

void Recording::addTrack(Track & aTrack, int position){
	//add track if it does not already exist
	map<int, Track*>::iterator itr = findPosition(aTrack);
	if(itr == tracks.end()) {
		if(position >=0 && position < MAX_NUMBER_OF_TRACKS)
		   tracks.insert({&aTrack.getID(),&aTrack});
	}
}

void Recording::removeTrack(Track & aTrack){
	//remove track from recording
	tracks.erase(aTrack.getID());
}

string Recording::toString()const {
	string indent = "     ";
	string s;
	s.append(to_string(id) + " " + title + " " + artist + " " + producer + " " + year);
	s.append("\n");
	s.append(indent + "Tracks:\n");
	for (map<int, Track*>::iterator it = tracks.begin() ; it != tracks.end(); ++it){
		 s.append(indent + it->second.toString() + "\n");
	}

	return s;
}

ostream & operator<<(ostream & out, const Recording & aRecording){
	out << aRecording.toString() << endl;
	return out;
}
