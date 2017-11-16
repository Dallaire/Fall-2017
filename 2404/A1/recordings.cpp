// Jacob Dallaire 100918375
#include <string>
#include <iostream>
#include "recordings.h"
#include "str_util.h"
using namespace std;

Recordings::Recordings(){
}
Recordings::~Recordings(){
for(vector<Recording*>::size_type i=0; i<albums.size(); i++)
  delete albums[i]; //delete songs in this container
}

vector<Recording*>::iterator Recordings::findPosition(Recording & aRecording){
	for (vector<Recording*>::iterator it = albums.begin() ; it != albums.end(); ++it)
		if(*it == &aRecording) return it;
	return albums.end();
}
Recording * Recordings::findByID(int anID){
	for (vector<Recording*>::iterator it = albums.begin() ; it != albums.end(); ++it)
		if((*it)->getID() == anID) return *it;
	return NULL;
}

string Recordings::addRecording(int albumID, string title, string artist, string producer, int year){
    string titleCased = StrUtil::toTitleCase(title);
    albums.push_back(new Recording(ID, titleCased, artist, producer, year))
    string message;
    message += "Added " + titleCased + " by " + artist + " to recordings" + "\n";
    return message;
}

string Recordings::deleteRecording(int albumID){
  vector<Recording*>::iterator index = findPosition(findByID(albumID));
	if(index != albums.end()) {
		Recording * theRecording = *index;
		albums.erase(index);
		delete theRecording; //free the memory of theRecording
	}
  string message;
  message += "Deleted recording with id: " + albumID + "\n";
  return message;
}

/*string Recordings::addTrack(string albumID, string songID, string track_number){
  string message;
  message += "Added song with id: " + songID + " to album with id: " + albumID + " as track_number" + track_number + "\n";
  return message;
}

string Recordings::deleteTrack(string songID, string albumID){
  string message;
  message += "Deleted song with id: " + songID + " from album with id: " + albumID + "\n";
  return message;
}*/

string Recordings::showRecordings(){
  string message;
  message += "Displaying all albums \n";
  for(vector<Recording*>::size_type i=0; i<albums.size(); i++)
       message+= (*albums[i]).toString() << "\n";
  return message;
}

/*
string Recordings::showTracks(string albumID){
  string message;
  message += "Displaying all tracks from album with id: " + albumID + " \n";
  return message;
}
*/
