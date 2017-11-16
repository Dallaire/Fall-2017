#ifndef _TRACK_H
#define _TRACK_H

#include <ostream>
#include <string>

class Track {
	public:
	Track(const int & aTrackID);
	~Track(void);
  int getID();
  string toString() const;

	private:
	int trackID;
  Song track_song;
};

ostream & operator<<(ostream & out, const Track & aTrack);

#endif
