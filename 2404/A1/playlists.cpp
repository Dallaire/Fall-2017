// Jacob Dallaire 100918375
#include <string>
#include <iostream>
#include "playlists.h"
using namespace std;

string Playlists::addPlaylist(string userID, string playlistName){
  string message;
  message += "Created empty playlist " + playlistName + " for user: " + userID + "\n";
  return message;
}

string Playlists::deletePlaylist(string userID, string playlistName){
  string message;
  message += "Deleted playlist " + playlistName + " for user: " + userID + "\n";
  return message;
}

string Playlists::showPlaylists(string userID){
  string message;
  message += "Displaying playlists for user with ID: " + userID + "\n";
  return message;
}

string Playlists::showPlaylistSongs(string playlistName, string userID){
  string message;
  message += "Displaying all songs on user: " + userID + " playlist: " + playlistName + "\n";
  return message;
}

string Playlists::addSongsPlaylist(string userID, string playlistName, string songID){
  string message;
  message += "Added song with id: " + songID + " to " + userID + "\'s playlist: " + playlistName + "\n";
  return message;
}

string Playlists::deletePlaylistSongs(string songID, string playlistName, string userID){
  string message;
  cout << "Enter -g to delete song from collection, or ENTER for just the playlist.";
  string input;
  cin >> input;
  if (input == "-g"){
    return message += "Deleted song with id: " + songID + " from the collection";
  }
  else {
    return message += "Deleted song with id: " + songID + " from playlist " + playlistName + "\n";
  }
}
