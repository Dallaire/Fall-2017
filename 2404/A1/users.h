// Jacob Dallaire 100918375
#include <string>
#include <iostream>
using namespace std;

class Users{
public:
  Users();
  ~Users();
  User * findByID(string anUserID);
  static string addUser(string userID, string userName);
  static string deleteUser(string userID);
  static string showUsers();

private:
  vector<Users*> allUsers;
  vector<User*>::iterator findPosition(User & aUser);
};
