#include <iostream>
#include <string>
using namespace std;

class Person {
private:
  string name;
  string email_address;
  string phone_number;
public:
  Person(string aName, string anEmailAddress, string aPhoneNumber);
  void printOn(ostream & out);
};
