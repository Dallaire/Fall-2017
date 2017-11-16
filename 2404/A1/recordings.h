// Jacob Dallaire 100918375s
#include <string>
#include <iostream>

using namespace std;

class Recordings{
public:
  Recordings();
  ~Recordings();
  Recording * findByID(int aRecordingID);
  static string addRecording(int albumID, string title, string artist, string producer, int year);
  static string deleteRecording(string albumID);
  static string showRecordings();


private:
  vector<Recording*> albums;
  vector<Recording*>::iterator findPosition(Recording & aRecording);
};
