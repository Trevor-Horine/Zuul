/*This is the class for rooms in zuul
 *Trevor Horine
 *12/1/17
 */
#include <iostream>
#include <cstring>
#include "rooms.h"
#include <map>

using namespace std;

//rooms class
rooms::rooms(char* newName, char* newItm){
  name = newName;
  itm = newItm;
}
//method to get name
char* rooms::getName(){
  return name;
}
//method to get item
char* rooms::getItm(){
  return itm;
}
//method to set item
void rooms::setItm(char* none){
  itm = none; 
}
//method to set exits
void rooms::setExits(char* dir, rooms* next){
  exits[dir] = next;
}
//method to get exits
void rooms::getExits() {
   for (map<char*, rooms*>::iterator it = exits.begin(); it != exits.end(); it++){
  cout << it -> first << endl;
   }
}
//method to get name of next room
rooms* rooms::getNextroom(char* dir){
   for (map<char*, rooms*>::iterator it = exits.begin(); it != exits.end(); it++){
     if(strcmp(dir, it -> first) == 0){
       return it -> second;
     }
   }
   return NULL;
}
