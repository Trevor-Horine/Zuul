/*this is the h file for Item.cpp
 *Trevor Horine
 *12/1/2017
 */
#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <cstring>

using namespace std;

class item{
 public:
  item(char* newDes);
  char* getDes();
 private:
  char* des;
};
#endif
