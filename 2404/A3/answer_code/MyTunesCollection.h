/* * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                   */
/*  Program:  MyTunes Music Player                   */
/*  Author:   Jacob Dallaire 100918375               */
/*            Louis Nel                              */
/*  Date:     21-SEP-2017                            */
/*                                                   */
/*  (c) 2017 Louis Nel                               */
/*  All rights reserved.  Distribution and           */
/*  reposting, in part or in whole, requires         */
/*  written consent of the author.                   */
/*                                                   */
/*  COMP 2404 students may reuse this content for    */
/*  their course assignments without seeking consent */
/* * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef _MYTUNESCOLLECTION_H
#define _MYTUNESCOLLECTION_H

#include <ostream>
#include <map>
#include <string>
using namespace std;
#include "UI.h"

template <typename S, typename T>
class MyTunesCollection {
	public:
	MyTunesCollection(){}
	~MyTunesCollection (void){
		collection.clear();
  }
  map<S, T> getCollection(){
    return collection;
  }
	T * findByID(int anID){
    return collection.find(anID);
  }
  T * findByID(const string anID){
    return collection.find(anID);
  }
	void add(T & aT){
  	collection.insert({aT.getID(), aT});
  }
	void remove(T & aT){
  	collection.erase(&aT.getID());
  }
	void showOn(UI & aView){
    for (typename std::map<S,T>::iterator it = collection.begin(); it != collection.end(); ++it){
       aView.printOutput(it->second.toString());
		 }
  }
	void showOn(UI & aView, int memberID){
    T * t = findByID(memberID);
    if( t != NULL)
         aView.printOutput(t->toString());
  }
  void showOn(UI & view, const string & memberID) {
    view.printOutput("User:");
    T * t = findByID(memberID);
    if( t != NULL)
         view.printOutput(t->toString());
  }
	private:
	map<S, T> collection;
	/*typename vector<T*>::iterator findPosition(T & aT){
  	for (typename vector<T*>::iterator it = collection.begin() ; it != collection.end(); ++it)
  		if(*it == &aT) return it;
  	return collection.end();
  }*/
};

#endif
