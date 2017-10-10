// Jacob Dallaire 100918375
#include <string>
#include <iostream>
#include "recordings.h"
#include "str_util.h"
using namespace std;

string Recordings::addRecording(string ID, string title, string artist, string producer, string year){
    string titleCased = StrUtil::toTitleCase(title);
    string message;
    message += "Added " + titleCased + " by " + artist + " to recordings" + "\n";
    return message;
}

string Recordings::deleteRecording(string albumID){
  string message;
  message += "Deleted recording with id: " + albumID + "\n";
  return message;
}

string Recordings::addTrack(string albumID, string songID, string track_number){
  string message;
  message += "Added song with id: " + songID + " to album with id: " + albumID + " as track_number" + track_number + "\n";
  return message;
}

string Recordings::deleteTrack(string songID, string albumID){
  string message;
  message += "Deleted song with id: " + songID + " from album with id: " + albumID + "\n";
  return message;
}

string Recordings::showRecordings(){
  string message;
  message += "Displaying all albums \n";
  return message;
}

string Recordings::showTracks(string albumID){
  string message;
  message += "Displaying all tracks from album with id: " + albumID + " \n";
  return message;
}
