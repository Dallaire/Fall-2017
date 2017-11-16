// Jacob Dallaire 100918375
#include <string>
#include <iostream>
#include "tracks.h"
#include "str_util.h"
using namespace std;

Tracks::Tracks(){
}
Tracks::~Tracks(void){
	for(vector<Track*>::size_type i=0; i<allTracks.size(); i++)
		delete allTracks[i]; //delete tracks in this container
}
vector<Track*>::iterator tracks::findPosition(Track & aTrack){
	for (vector<Track*>::iterator it = allTracks.begin() ; it != allTracks.end(); ++it)
		if(*it == &aTrack) return it;
	return allTracks.end();
}
Track * Tracks::findByID(int anID){
	for (vector<Track*>::iterator it = allTracks.begin() ; it != allTracks.end(); ++it)
		if((*it)->getID() == anID) return *it;
	return NULL;
}

string Tracks::addTrack(int id){
  allTracks.push_back(new Track(id));
  string message;
  message += "Added Track with ID "+ id + " to Track collection" + "\n";
  return message;
}

string Tracks::deleteTrack(int id){
  vector<Track*>::iterator index = findPosition(findByID(id));
	if(index != allTracks.end()) {
		Track * theTrack = *index;
		allTracks.erase(index);
		delete theTrack; //free the memory of theTrack
	}
  string message;
  message += "Deleted track with id: " + id + "\n";
  return message;
}

string Songs::showTracks(){
  string message;
  message += "Displaying all tracks \n";
  for(vector<Track*>::size_type i=0; i<allTracks.size(); i++)
       message+= (*allTracks[i]).toString() << "\n";
  return message;
}
