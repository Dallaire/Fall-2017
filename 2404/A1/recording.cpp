#include <iostream>
#include <string>
using namespace std;

#include "recording.h"

Recording::Recording(const int & anId, const string & aTitle, const string anArtist, const string aProducer, const int aYear){
	title = aTitle;
  artist = anArtist;
	producer = aProducer;
	id = anId;
  year = aYear;
}
Recording::~Recording(){
	cout << "~Recording(void) "  << this << endl;
}

Track * Tracks::findByID(int anID){
	for (vector<Track*>::iterator it = allTracks.begin() ; it != allTracks.end(); ++it)
		if((*it)->getID() == anID) return *it;
	return NULL;
}

string Recording::addRecordingTrack(int id){
  allTracks.push_back(new Track(id));
  string message;
  message += "Added Track with ID "+ id + " to Track collection" + "\n";
  return message;
}

int Recording::getID(){return id;}

string Recording::toString()const {
	return to_string(id) + " " + title + " " + artist+ " " + producer + " " + year;
}

ostream & operator<<(ostream & out, const Recording & aRecording){
	out << aRecording.toString() << endl;
	return out;
}
