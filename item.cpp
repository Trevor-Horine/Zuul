/*This is the class for items in zuul
 *Trevor Horine
 *12/1/2017
 */
#include <iostream>
#include <cstring>
#include "item.h"

using namespace std;

//item class
item::item(char* newDes){
  des = newDes;
}

//method to get description of item
char* item::getDes(){
  return des;
}
