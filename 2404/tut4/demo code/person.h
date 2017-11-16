#ifndef _person_h
#define _person_h

#include <iostream>
#include <cstring>
#include "date.h"
#include "emailaddress.h"


using namespace std;

class Person
{
public:
Person(const char * aName, const char * userID, const char * domain, Date aDate) {
//This constructor should create heap objects

	name = new char[strlen(aName) + 1];
    strcpy (name, aName);
	emailAddress = new EmailAddress(userID, domain);
	birthday = new Date(aDate);

	cout << "\nPerson(...) CREATING: ";
	printOn(cout);


}

Person(const Person & aPerson){
	name = new char[strlen(aPerson.name)+1];
	strcpy (name, aPerson.name);
	emailAddress = new EmailAddress(*(aPerson.emailAddress));
	birthday = new Date(*(aPerson.birthday));

	cout << "\nPerson(...) CREATING: ";
	printOn(cout);
}

Person & operator=(const Person & aPerson){
		if(&aPerson != this) {
 			delete [] name;
 			delete emailAddress;
			delete birthday;
 			name = new char[strlen(aPerson.name) + 1];
			strcpy (name, aPerson.name);
			emailAddress = new EmailAddress(*(aPerson.emailAddress));
			birthday = new Date(*(aPerson.birthday));

		}
return *this;
}

~Person() {
   //notice the destructor expects these to be on the heap
	cout << "\n~Person() DELETING: ";
	printOn(cout);

    delete birthday;
	delete emailAddress;
	delete [] name;

}


void printOn(ostream & ostr) const {
  ostr << name << " (" << *birthday << ") " << *emailAddress;
}

private:
   char * name; //pointer to a person's name
   EmailAddress * emailAddress; //pointer to a person's email address
   Date * birthday; //pointer to persons birthday


}; //end class Person

ostream & operator<<(ostream & out, const Person & p) {
   p.printOn(out);
   return out;
}

#endif
