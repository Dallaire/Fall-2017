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
#include <vector>
#include <string>
using namespace std;
#include "UI.h"

template <typename T>
class MyTunesCollection {
	public:
	MyTunesCollection(){}
	~MyTunesCollection (void){
  	for(int i=0; i<collection.size(); i++)
  		delete collection[i]; //delete T in this container
  }
  vector<T*> getCollection(){
    return collection;
  }
	T * findByID(int anID){
    for (typename vector<T*>::iterator it = collection.begin() ; it != collection.end(); ++it)
  		if((*it)->getID() == anID) return *it;
  	return NULL;
  }
  T * findByID(const string anID){
    for (typename vector<T*>::iterator itr = collection.begin() ; itr != collection.end(); ++itr)
  		if(((*itr)->getUserID()).compare(anID) == 0) return *itr;
  	return NULL;
  }
	void add(T & aT){
  	collection.push_back(&aT);
  }
	void remove(T & aT){
  	typename vector<T*>::iterator index = findPosition(aT);
  	if(index != collection.end()) {
  		T * theT = *index;
  		collection.erase(index);
  		delete theT; //free the memory of theT
  	}
  }
	void showOn(UI & aView){
    for(int i=0; i<collection.size(); i++)
         aView.printOutput((*collection[i]).toString());
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
	vector<T*> collection;
	typename vector<T*>::iterator findPosition(T & aT){
  	for (typename vector<T*>::iterator it = collection.begin() ; it != collection.end(); ++it)
  		if(*it == &aT) return it;
  	return collection.end();
  }
};

#endif
