// Jacob Dallaire 100918375
#include <string>
#include <iostream>
#include "users.h"
using namespace std;

string Users::addUser(string userID, string userName){
  string message;
  message += "Added user " + userName + " with id: " + userID + "\n";
  return message;
}

string Users::deleteUser(string userID){
  string message;
  message += "Deleted user with id: " + userID + "\n";
  return message;
}

string Users::showUsers(){
  string message;
  message += "Displaying all users \n";
  return message;
}
