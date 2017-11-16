#ifndef _USER_H
#define _USER_H

#include <ostream>
#include <string>

class User {
	public:
	User(const string anUserID, const string aName);
	~User(void);
	Playlist * findByName(string playlistName);
	string User::addPlaylist(string playlistName);
	string User::addPlaylist(string playlistName);
	string User::showPlaylists();
  string getID();
  string toString() const;

	private:
	string userID;
	string name;
	vector<Playlist> playlists;
	vector<Playlist*>::iterator findPosition(Playlist & aPlaylist);
};

ostream & operator<<(ostream & out, const User & aUser);

#endif
