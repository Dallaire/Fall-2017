// Jacob Dallaire 100918375s
#include <string>
#include <iostream>

using namespace std;

class Recordings{
public:
  static string addRecording(string ID, string title, string artist, string producer, string year);
  static string deleteRecording(string albumID);
  static string addTrack(string albumID, string songID, string track_number);
  static string deleteTrack(string songID, string albumID);
  static string showRecordings();
  static string showTracks(string albumID);
};
