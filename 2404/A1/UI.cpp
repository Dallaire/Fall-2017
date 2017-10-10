// Jacob Dallaire 100918375
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include "UI.h"
#include "playlists.h"
#include "users.h"
#include "songs.h"
#include "recordings.h"
using namespace std;

vector<string> sessionLog; //Log of commands
bool state = true;         //Set to false when .quit called ending session
bool loginput = false;     //turns on logging while true
bool logoutput = false;

void UI::read(string fileName){     //Allows for scripting of commands by reading from a txt file of commands
  ifstream iFile(fileName, ifstream::in);
  string input="";
	if(!iFile){
		cout << "ERROR: could not open file " << fileName << "\n";
	}

  else{
    while(getline(iFile, input)){
  		parse(input);
    }
  }
  iFile.close();
}

void UI::log(string command, string filename){ //Keeps a record of input and outputs
  if (command == "clear"){
    sessionLog.clear();
  }
  else if (command == "start"){
    loginput = true;
    logoutput = false;
  }
  else if (command == "start_output"){
    logoutput = true;
    loginput = false;
  }
  else if (command == "start_both"){
    loginput = true;
    logoutput = true;
  }
  else if (command == "stop"){
    loginput = false;
    logoutput = false;
  }
  else if (command == "show"){
    cout << "LOG--------------------------------\n";
    for (int i=0; i<sessionLog.size(); i++){
      cout << sessionLog[i] << "\n";
    }
    cout << "-----------------------------------\n";
  }
  else if (command == "save"){
    ofstream oFile(filename, ofstream::out);
    for (int i=0; i< sessionLog.size(); i++){
      oFile << sessionLog[i];
    }
    oFile.close();
  }
}

void UI::help(){  //Displays contents of help.txt a list of commands the CLI accepts
  string input ="";
  ifstream iFile("help.txt", ifstream::in);
  while(getline(iFile, input)){
    cout << input << "\n";
  }
}

void UI::parse(string input){ //Parses user input to execute commands
  std::vector<std::string> arg;
  std::string s = input;
  string word = "";
  for( size_t i=0; i<s.length(); i++){
      char c = s[i];
      if( c == ' ' ){
        arg.push_back(word);
        word =  "";
      }
      else if(c == '\"' ){
          i++;
          while( s[i] != '\"' ){
            word.push_back(s[i]);
            i++;
          }
      }
      else{
          word.push_back(c);
      }
  }
  arg.push_back(word);

  string message="";
//Below here is just cases for which command is called
  if (arg[0]==".read"){
    UI::read(arg[1]);
  }

  if (arg[0]== "add"){  //various add commands
    if (arg[1]== "-s"){
      message = Songs::addSong(arg[2], arg[3], arg[4]);
    }
    else if (arg[1] == "-r"){
      message = Recordings::addRecording(arg[2], arg[3], arg[4], arg[5], arg[6]);
    }
    else if (arg[1] =="-t"){
      message = Recordings::addTrack(arg[2], arg[3], arg[4]);
    }
    else if (arg[1] == "-u"){
      message = Users::addUser(arg[2], arg[3]);
    }
    else if (arg[1] == "-p"){
      message = Playlists::addPlaylist(arg[2], arg[3]);
    }
    else if (arg[1] =="-l"){
      message = Playlists::addSongsPlaylist(arg[2], arg[3], arg[4]);
    }
  }
  else if (arg[0] == "delete"){   //delete commands
    if (arg[1]== "-s"){
      message = Songs::deleteSong(arg[2]);
    }
    else if (arg[1] == "-r"){
      message = Recordings::deleteRecording(arg[2]);
    }
    else if (arg[1] =="-t"){
      message = Recordings::deleteTrack(arg[2], arg[3]);
    }
    else if (arg[1] == "-u"){
      message = Users::deleteUser(arg[2]);
    }
    else if (arg[1] == "-p"){
      message = Playlists::deletePlaylist(arg[2], arg[3]);
    }
    else if (arg[1] =="-l"){
      message = Playlists::deletePlaylistSongs(arg[2], arg[3], arg[4]);
    }
  }
  else if (arg[0] == "show"){  //Display commands
    if (arg[1]== "songs"){
      if (arg.size()==2){
        message = Songs::show();
      }
      else if (arg.size() == 5) {
        message = Playlists::showPlaylistSongs(arg[3], arg[5]);
      }
      else{
        cout << "Input ERROR Please check .help\n";
      }
    }
    else if (arg[1] == "recordings"){
      message = Recordings::showRecordings();
    }
    else if (arg[1] =="tracks"){
      message = Recordings::showTracks(arg[3]);
    }
    else if (arg[1] == "users"){
      message = Users::showUsers();
    }
    else if (arg[1] == "playlists"){
      message = Playlists::showPlaylists(arg[3]);
    }
  }
  else if (arg[0] == ".log"){ //log commands
    if (arg[1] == "start"){
      log(arg[1]);
    }
    else if(arg[1] == "clear"){
      log(arg[1]);
    }
    else if(arg[1] == "start_output"){
      log(arg[1]);
    }
    else if(arg[1] == "start_both"){
      log(arg[1]);
    }
    else if(arg[1] == "stop"){
      log(arg[1]);
    }
    else if(arg[1] == "show"){
      log(arg[1]);
    }
    else if(arg[1] == "save"){
      log(arg[1], arg[2]);
    }
  }
  else if(arg[0] == ".help"){ //Help
    UI::help();
  }
  else if(arg[0] == ".quit"){ //ends session
    state=false;
  }
  else {
    message = "Comment entered or INPUT ERROR Please check .help\n";
  }
  if (logoutput){
     sessionLog.push_back(message);
  }
  cout << message << "\n";
}

void UI::inittialize(){ //function that ties in parse to user input
  while (state){
    string input="";
    cout << "CMD or .quit to exit: ";
    getline(cin, input);
    if (loginput){
      sessionLog.push_back(input);
    }
    if (input == ".help"){
      read("help.txt");
    }
    else{
      parse(input);
    }
  }
}

UI::UI(){}; //Constructure
