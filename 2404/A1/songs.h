// Jacob Dallaire 100918375
#include <string>
#include <iostream>
using namespace std;

class Songs{
public:
  Songs();
  ~Songs(void);
  Song * findByID(int anID);
  static string addSong(int id, string title, string composer);
  static string deleteSong(int songid);
  static string show();

private:
  vector<Song*> library;
	vector<Song*>::iterator findPosition(Song & aSong);
};
