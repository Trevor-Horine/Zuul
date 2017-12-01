/*this is the h file for rooms.cpp
 *Trevor Horine
 *12/1/2017
 */

#ifndef ROOMS_H
#define ROOMS_H
#include <iostream>
#include <cstring>
#include <map>

using namespace std;

class rooms{
 public:
  rooms(char* newName, char* newItm);
  char* getName();
  char* getItm();
  void setItm(char*);
  void setExits(char*, rooms*);
  void getExits();
  rooms* getNextroom(char*);
 private:
  char* name;
  char* itm;
  map<char*, rooms*> exits;
};
#endif
