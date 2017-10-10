// Jacob Dallaire 100918375
#include <string>
#include <iostream>

using namespace std;

class Playlists{
public:
  static string addPlaylist(string userID, string playlistName);
  static string deletePlaylist(string userID, string playlistName);
  static string showPlaylists(string userID);
  static string showPlaylistSongs(string playlistName, string userID);
  static string addSongsPlaylist(string userID, string playlistName, string songID);
  static string deletePlaylistSongs(string songID, string playlistName, string userID);
};
