// Jacob Dallaire 100918375
#include <string>
#include <iostream>
using namespace std;

class Tracks{
public:
  Tracks();
  ~Tracks(void);
  Track * findByID(int anID);
  static string addTrack();
  static string deleteTrack();
  static string showTracks();

private:
  vector<Track*> allTracks;
	vector<Track*>::iterator findPosition(Track & aTrack);
};
