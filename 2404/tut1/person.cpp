#include <iostream>
#include <string>
#include "person.h"
using namespace std;

  Person::Person(string aName, string anEmailAddress, string aPhoneNumber){
    name = aName;
    email_address = anEmailAddress;
    phone_number = aPhoneNumber;
  }
  void Person::printOn(ostream & out){
    out << name
        << "  email: "
        << email_address
        << "  phone: "
        << phone_number;
}
