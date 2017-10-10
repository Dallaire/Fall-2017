// Jacob Dallaire 100918375
#include <string>
#include <iostream>
using namespace std;

class Users{
public:
  static string addUser(string userID, string userName);
  static string deleteUser(string userID);
  static string showUsers();
};
