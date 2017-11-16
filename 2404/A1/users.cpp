// Jacob Dallaire 100918375
#include <string>
#include <iostream>
#include "users.h"
using namespace std;

Users::Users(){
}

Users::~Users(){
for(vector<User*>::size_type i=0; i<allUsers.size(); i++)
  delete allUsers[i]; //delete songs in this container
}

vector<User*>::iterator Users::findPosition(User & aUser){
	for (vector<User*>::iterator it = allUsers.begin() ; it != allUsers.end(); ++it)
		if(*it == &aUser) return it;
	return allUsers.end();
}

User * Users::findByID(string anUserID){
	for (vector<User*>::iterator it = allUsers.begin() ; it != allUsers.end(); ++it)
		if((*it)->getID() == anUserID) return *it;
	return NULL;
}

string Users::addUser(string userID, string userName){
  allUsers.push_back(new User(userID, userName));
  string message;
  message += "Added user " + userName + " with id: " + userID + "\n";
  return message;
}

string Users::deleteUser(string userID){
  vector<User*>::iterator index = findPosition(findByID(userID));
	if(index != allUsers.end()) {
		User * theUser = *index;
		allUsers.erase(index);
		delete theUser; //free the memory of theUser
  }
  string message;
  message += "Deleted user with id: " + userID + "\n";
  return message;
}

string Users::showUsers(){
  string message;
  message += "Displaying all users \n";
  for(vector<User*>::size_type i=0; i<allUsers.size(); i++)
       message+= (*allUsers[i]).toString() << "\n";
  return message;
}
