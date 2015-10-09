

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
      books.push_back(new Book(folder+ ent->d_name));
    }
    ent = readdir(directory);
  }
  closedir(directory);
}

Library::~Library(){
 // TODO:
 for(unsigned int i = 0; i < books.size(); i++){
  delete books[i];
 }
}

int Library::getBookCount(){
  return books.size();
}

vector<string> Library::getBookTitles(){
  // TODO:
  vector<string> ret;
  for(unsigned int i = 0; i < books.size(); i++){
    Book* book = books.at(i);
    
    if(book != NULL){
      string title = book->getTitle();
      ret.push_back(title);
    }
  } 
 return ret;
}
  
Book* Library::getBook(unsigned int i){
  // TODO:
  Book*book = NULL;
  if(books.size() > i){
    return books.at(i);
  }
  return book;
}

Book* Library::getBook(string title){
// TODO:
  Book* book = NULL;
  for(unsigned int i=0; i<books.size(); i++){
    if(title == books[i]->getTitle()){
      return books[i];
    } 
  }      
  return book;
}

float Library::getSimilarity(Book* one, Book* two){
  // TODO:
  vector<float> a = one-> letterPercent();
  vector<float> b = two-> letterPercent();
  float diff = 0;

  float aver;
  for(int i=0; i < 26; i++){
    diff = diff + abs(a[i] - b[i]);
  }
  aver = diff/26;
  return aver;
}
