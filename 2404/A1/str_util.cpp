// Jacob Dallaire 100918375
#include <string>
#include <sstream>
#include "str_util.h"
using namespace std;

string StrUtil::toTitleCase(string str) {
	string s;
	if(str.compare(0,4,"the ")==0){
		string sub = str.substr(4,str.size()-4);
		for(int i=0; i<(sub.length()); i++){
			if(i==0 || sub.substr(i-1,1)==" "){
				s.append(1,toupper(sub.at(i)));
			}
			else{
				s.append(1, sub.at(i));
			}
		}
		s.append(", The");
	}
	else{
		for(int i=0; i<(str.size()); i++){
			if(i==0 || str.substr(i-1,1)==" "){
				s.append(1,toupper(str.at(i)));
			}
			else{
				s.append(1,str.at(i));
			}
		}
	}
	return s;
	}
