#ifndef _PLAYLIST_H
#define _PLAYLIST_H

#include <ostream>
#include <string>

class Playlist {
	public:
	Playlist(const string playlistName);
	~Playlist(void);
	Track * findByID(int aTrackID);
  static string getPlaylistName();
  string toString() const;

	private:
	string playlistName;
	vector<Track> tracks;
	vector<Track*>::iterator findPosition(Track & aTrack);
};

ostream & operator<<(ostream & out, const Track & aTrack);

#endif
