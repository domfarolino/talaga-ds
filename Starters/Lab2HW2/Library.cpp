/*
	Library implementation.
	Paul Talaga
	August 2015
*/

#include <string>
#include <string.h>
#include <dirent.h>
#include <iostream>
#include <cmath>

#include "Library.h"


using namespace std;

Library::Library(string folder){
  // Open a directory and read the contents
  DIR* directory = opendir(folder.c_str());
  dirent* ent = readdir(directory);
  while(ent){
    if(strlen(ent->d_name) > 2){  // strlen gets the length of a c-string (char*)
      // Assume if the length > 2 it is a valid file
      // TODO: chage inside here to create and store new books!
      cout << ent->d_name << endl;
    }
    ent = readdir(directory);
  }
  closedir(directory);
}

Library::~Library(){
 // TODO:
}

int Library::getBookCount(){
  // TODO:
  return books.size();
}

vector<string> Library::getBookTitles(){
  // TODO:
  vector<string> ret;
 return ret;
}
  
Book* Library::getBook(unsigned int i){
  // TODO:
  return (Book*)NULL;
}

Book* Library::getBook(string title){
// TODO:
  return (Book*)NULL;
}

float Library::getSimilarity(Book* one, Book* two){
  // TODO:
  return 0.0;
}
