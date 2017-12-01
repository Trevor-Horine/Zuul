/*This is a game of zuul
 *Author: Trevor Horine
 *12/1/2017
 */
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include "rooms.h"
#include "item.h"

using namespace std;

//create methods
void go(rooms* &current, char* in);
void get(vector <item*> items, vector <item*> &inven, char* in, rooms* current);
void drop(vector <item*> &inven, char* in, rooms* current);
void help();
void inventory(vector<item*> inven);
void lose(bool &playing);

//main
int main(){
  //variables
  bool playing = true;
  vector <item*> inven;
  vector <item*> items;
  //items
  item* flashlight = new item("FLASHLIGHT");
  item* knife = new item("KNIFE");
  item* climbinggear = new item("CLIMBING GEAR");
  item* boat = new item("BOAT");
  item* lj = new item("LIFE JACKET");
  //add to vector
  items.push_back(flashlight);
  items.push_back(knife);
  items.push_back(climbinggear);
  items.push_back(boat);
  items.push_back(lj);
  //rooms
  rooms* woods = new rooms("You see trees it must be a forest. There are mountians to the south and they look cold. There is a river to the north but you can't swim. There are dirt paths to the east and west.", "FLASHLIGHT");
  rooms* path1 = new rooms("This is a dirt path it must go somewhere. right? There are mountians to the south and they look cold. There is a river to the north but you can't swim. There is a cave to the west, and a wooded area to the east", "NONE");
  rooms* cave = new rooms("This is a cave, It is cold and dark. There is a river to the north but you can't swim. There is a path to the east.", "BOAT");
  rooms* path2 = new rooms("This is a dirt path it must go somewhere. right? There are mountians to the south and they look cold. There is a river to the north but you can't swim. There is a cabin to the east and a wooded area to the west.", "NONE");
  rooms* cabin = new rooms("You have found a cabin in the woods how spooky. There are mountians to the south and they look cold. There is a river to the north but you can't swim. There is a path to the west and a clif to the east. There is also a basement.", "CLIMBING GEAR");
  rooms* basement = new rooms("This is the basement of the cabin it is dark. The cabin is back up stairs", "LIFE JACKET");
  rooms* clif = new rooms("It is a long way down. you should not go any further There are mountians to the south and they look cold. There is a waterfall to the north but you can't swim.", "KNIFE");
  rooms* river1 = new rooms("This river is an easier way to travel that by land. There is a cave to the south and a mountian to the north, it looks really cold.", "NONE");
  rooms* river2 = new rooms("This river is an easier way to travel than by land. There is a path to the south and a mountian to the north, it looks really cold.", "NONE");
  rooms* river3 = new rooms("This river is an easier way to travel than by land. There is a forest to the south and a mountian to the north, it loos really cold.", "NONE");
  rooms* river4 = new rooms("This river is an easier way to travel than by land. There is a path to the south and a mountian to the north, it looks really cold.", "NONE");
  rooms* river5 = new rooms("This river is an easier way to travel than by land. There is a cabin in the woods to the south and a mountian to the north, it looks relly cold, and a waterfall to the east.", "NONE");
  rooms* waterfall = new rooms("You died! You went over the waterfall!", "NONE");
  rooms* mt1 = new rooms("You died of hypothermia in the mountians!", "NONE");
  rooms* mt2 = new rooms("You died of hypothermia in the mountians!", "NONE");
  rooms* mt3 = new rooms("You died of hypothermia in the mountians!", "NONE");
  rooms* mt4 = new rooms("You died of hypothermia in the mountians!", "NONE");
  rooms* mt5 = new rooms("You died of hypothermia in the mountians!", "NONE");
  rooms* mt6 = new rooms("You died of hypothermia in the mountians!", "NONE");
  rooms* mt7 = new rooms("You died of hypothermia in the mountians!", "NONE");
  rooms* mt8 = new rooms("You died of hypothermia in the mountians!", "NONE");
  rooms* mt9 = new rooms("You died of hypothermia in the mountians!", "NONE");
  rooms* mt10 = new rooms("You died of hypothermia in the mountians!", "NONE");
  rooms* mt11 = new rooms("You died of hypothermia in the mountians!", "NONE");
  rooms* win = new rooms("You have escaped and won!", "NONE");
  rooms* current = woods;
  //set exits
  woods -> setExits("NORTH", river3);
  woods -> setExits("SOUTH", mt8);
  woods -> setExits("EAST", path2);
  woods -> setExits("WEST", path1);
  path1 -> setExits("NORTH", river2);
  path1 -> setExits("SOUTH", mt7);
  path1 -> setExits("EAST", woods);
  path1 -> setExits("WEST", cave);
  cave -> setExits("NORTH", river1);
  cave -> setExits("EAST", path1);
  river1 -> setExits("NORTH", mt1);
  river1 -> setExits("SOUTH", cave);
  river1 -> setExits("EAST", river2);
  river2 -> setExits("NORTH", mt2);
  river2 -> setExits("SOUTH", path1);
  river2 -> setExits("EAST", river3);
  river2 -> setExits("WEST", river1);
  river3 -> setExits("NORTH", mt3);
  river3 -> setExits("SOUTH", woods);
  river3 -> setExits("EAST", river4);
  river3 -> setExits("WEST", river2);
  river4 -> setExits("NORTH", mt4);
  river4 -> setExits("SOUTH", path2);
  river4 -> setExits("EAST", river5);
  river4 -> setExits("WEST", river3);
  river5 -> setExits("NORTH", mt5);
  river5 -> setExits("SOUTH", cabin);
  river5 -> setExits("EAST", waterfall);
  river5 -> setExits("WEST", river4);
  path2 -> setExits("NORTH", river4);
  path2 -> setExits("SOUTH", mt9);
  path2 -> setExits("EAST", cabin);
  path2 -> setExits("WEST", woods);
  cabin -> setExits("NORTH", river5);
  cabin -> setExits("SOUTH", mt10);
  cabin -> setExits("EAST", clif);
  cabin -> setExits("WEST", path2);
  cabin -> setExits("DOWN", basement);
  basement -> setExits("UP", cabin);
  clif -> setExits("NORTH", waterfall);
  clif -> setExits("SOUTH", mt11);
  clif -> setExits("WEST", cabin);
  clif -> setExits("DOWN", win);
  // display instructions
  help();
  //loop to keep playing
  while (playing == true){
    //more variables
    char* input = new char[100];
    char* action = new char[100];
    char* in = new char[100];
    char* dis = new char[100];
    char* winlose = new char[100];
    int space = 0;
    //loseing conditions
    dis = current -> getName();
    for(int i = 0; i < 100; i++){
      if(dis[i] == ' '){
	space++;
	if (space == 2){
	  break;
	}
      }
      winlose[i] = dis[i];
    }
    for(int i = 0; i < 100; i++){
      winlose[i] = toupper(winlose[i]);
    }
    if(strcmp(winlose, "YOU DIED") == 0){
      cout << current -> getName() << " ";
      lose(playing);
      break;
    }
    if(strcmp(winlose, "THIS RIVER") == 0){
      bool bo = false;
      for(vector <item*>::iterator it = inven.begin(); it != inven.end(); it++){
	if(strcmp((*it) -> getDes(), "BOAT") == 0){
	  bo = true;
	  break;
	}
	else if(strcmp((*it) -> getDes(),"LIFE JACKET") == 0){
	  bo = true;
	  break;
	}
      }
      if(bo == false){
	cout << "You drownd! ";
	lose(playing);
	break;
      }
    }
    if(current == waterfall){
      cout << "You fell over the waterfall. ";
      lose(playing);
      break;
    }
    if(current == cave){
      bool bo = false;
      for(vector <item*>::iterator it = inven.begin(); it != inven.end(); it++){
	if(strcmp((*it) -> getDes(), "KNIFE") == 0){
	  bo = true;
	  break;
	}
      }
      if(bo == false){
	cout << "You were eaten! ";
	lose(playing);
	break;
      }
    }
    if(current == basement){
      bool bo = false;
      for(vector <item*>::iterator it = inven.begin(); it != inven.end(); it++){
        if(strcmp((*it) -> getDes(), "FLASHLIGHT") == 0){
          bo = true;
          break;
        }
      }
      if(bo == false){
        cout << "You triped and fell! ";
        lose(playing);
        break;
      }
    }
    if(current == win){
      bool bo = false;
      for(vector <item*>::iterator it = inven.begin(); it != inven.end(); it++){
        if(strcmp((*it) -> getDes(), "CLIMBING GEAR") == 0){
          bo = true;
          break;
        }
      }
      if(bo == false){
        cout << "You fell! ";
        lose(playing);
        break;
      }
      //winning condition
      else if(bo == true){
	cout << "You have gotten out of the valley! You Win!" << endl;
	break;
      }
    }
    //diaplay current room info
    cout << current -> getName() << endl;
    cout << "Exits:" << endl;
    current -> getExits();
    cout << "Items:" << endl;
    cout << current -> getItm() << endl;
    //read in action
    cin.getline(input, 100);
    //split it in to two words
    for(int i = 0; i <100; i++){
      if(input[i] == ' '){
	break;
      }
      else{
	action[i] = input[i];
      }
    }
    int h = 0;
    for(int i = 0; i < 100; i++){
      if(action[i] != NULL){
	if(input[i] == action[i]){
	  
	}
      }
      if(action[i] == NULL){
	in[h] = input[i + 1];
	h++;
      }
    }
    for(int i = 0; i < 100; i++){
      action[i] = toupper(action[i]);
    }
    for(int i = 0; i < 100; i++){
      in[i] = toupper(in[i]);
    }
    //what to do for each action
    if (strcmp(action, "GO") == 0){
      go(current, in);
    }
    if (strcmp(action, "GET") == 0){
      get(items, inven, in, current);
    }
    if (strcmp(action, "DROP") == 0){
      drop(inven, in, current);
    }
    if(strcmp(action, "HELP") == 0){
      help();
    }
    if (strcmp(action, "INVENTORY") == 0){
      inventory(inven);
    }
    if(strcmp(action, "QUIT") == 0){
      playing = false;
    }
  }
}
//method to move between rooms
void go(rooms* &current, char* in){
  if (current -> getNextroom (in) == NULL){
    cout << "there is no exit there!" << endl;
  }
  else{
    current = current -> getNextroom(in);
  } 
}
//method to pick up items
void get(vector <item*> items, vector <item*> &inven, char* in, rooms* current){
  char* desc = new char[100];
  char* h = new char[100];
  h = current -> getItm();
  if(strcmp(in, h) ==0){
    for(vector<item*>::iterator it = items.begin(); it != items.end(); it++){
      if(strcmp(in, (*it) -> getDes()) == 0){
	desc = (*it) -> getDes();
	item* i = new item(desc);
	inven.push_back(i);
	cout << "Item was added to your inventory." << endl;
	current -> setItm("NONE");
      }
      else{

      }
    }
  }
}
//method to drop items
void drop (vector <item*> &inven, char* in, rooms* current){
   for(vector<item*>::iterator it = inven.begin(); it != inven.end(); it++){
     if(strcmp(in, (*it) -> getDes()) != 0){
       cout << "That is not in your inventory" << endl;
     }
   }
   current -> setItm(in);
   for(vector<item*>::iterator it = inven.begin(); it != inven.end(); it++){
     if(strcmp(in, (*it) -> getDes()) == 0){
       inven.erase(it);
       break;
     }
   }
}
//method to display instructions
void help(){
  cout << "You are traped in a valley you must escape to live. \nGo followed by a direction will move from room to room. \nGet followed by an item will add it to your inventry. \nDrop followed by an item will remove it from your inventory. \nInventory will tell you what is in your inventory. \nQuit will end he game. \nHelp will bring this information back in case you forget." << endl;
}
//method to display inventory
void inventory(vector<item*> inven){
  if(inven.empty()){
    cout << "Your inventory is empty!" << endl;
  }
  for(vector<item*>::iterator it = inven.begin(); it != inven.end(); it++){
    cout << (*it)-> getDes() << endl;
  }
}
//mothod for when player loses
void lose(bool &playing){
  cout << "You have died and can no longer escape! You lose!" << endl;
  playing = false;
}
