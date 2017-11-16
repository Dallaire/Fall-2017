#ifndef _RECORDING_H
#define _RECORDING_H

#include <ostream>
#include <string>

class Song {
	/*
	Song represents a musical composition (not an audio recording)
	*/
	public:
	Recording(const int & anId= -1, const string & aTitle, const string anArtist, const string aProducer, const int aYear);
	~Recording(void);
  string getID();
  string toString() const;
	Track * findByID(int anID);
	static string addRecordingTrack(int albumID, int trackID, int track_number);
  static string deleteRecordingTrack(int trackID, int albumID);
	static string showRecordingTracks(int albumID);

	private:
	string title;
	string producer;
	int id;
  int year;
	vector<Track*> recordingTracks;
	vector<Track*>::iterator findPosition(Recording & aRecording);
};

ostream & operator<<(ostream & out, const Recording & aRecording);

#endif
