// Jacob Dallaire 100918375
#ifndef STR_UTIL_H
#define STR_UTIL_H

#include <string>
#include <sstream>
using namespace std;

//String Utilties Class
//Should this be done by sub-classing the <string> lib?

class StrUtil
{
  public:
  static string toTitleCase(string str);
};
#endif
