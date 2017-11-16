#include <iostream>
#include <string>
using namespace std;

#include "song.h"

Track::Track(const int & aTrackID){
	trackID = aTrackID;
}
Track::~Track(){
  cout << "~Track(void) "  << this << endl;
}

int Track::getID(){return trackID;}

string Track::toString()const {
	return trackID + " " + track_song;
}

ostream & operator<<(ostream & out, const Track & aTrack){
	out << aTrack.toString() << endl;
	return out;
}
