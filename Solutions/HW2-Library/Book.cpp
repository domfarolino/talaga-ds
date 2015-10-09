/*
	Implementation for Book class.
	Paul Talaga
	August 2015
*/

#include <string>
#include <fstream>
#include <iostream>

#include "Book.h"

using namespace std;

Book::Book(string filename){
    // Set defaults
    title = "";
    first = "";
    last = "";
    text = "";
    // Open file and read contents
    fstream file;
    file.open(filename.c_str(), ios::in);
    string line;
    while(file){
      getline(file, line);
      if(line.substr(0,1) == "!"){ // Command line!
        size_t loc = line.find("!", 1);
        if(loc == string::npos){
          break;
        }
        if(line.substr(0,7) == "!Title:"){
          title = line.substr(7, loc-7);
        }else if(line.substr(0,14) == "!Author-First:"){
          first = line.substr(14, loc - 14);
        }else if(line.substr(0,13) == "!Author-Last:"){
          last = line.substr(13, loc - 13);
        }
      }else{
        text = text + line + "\n";
      }
    }
    file.close();
}
  
Book::Book(string title, string first, string last, string text){
  this->title = title;
  this->first = first;
  this->last = last;
  this->text = text;
}
  
// Getters
string Book::getTitle(){
  return title;
}
  
string Book::getFullAuthor(){
  return first + " " + last;
}
  
string Book::getAuthorFirst(){
  return first;
}
  
string Book::getAuthorLast(){
  return last;
}
  
unsigned int Book::getCharacterCount(){
  return text.length();
}
  
unsigned int Book::getLineCount(){
  if(text == ""){
    return 0;
  }
  // The dumb way
  int newlines = 1;
  for(unsigned int i = 0; i < text.length(); i++){
    if(text[i] == '\n'){
      newlines++;
    }
  }
  return newlines;
}
  
unsigned int Book::getWordCount(string word){
  word = " " + word + " ";
  int word_length = word.length();
  // The dumb way
  int count = 0;
  for(unsigned int i = 0; i < text.length(); i++){
    if(text.substr(i, word_length).compare(word) == 0){
      count++;
    }
  }
  return count;
}

vector<float> Book::letterPercent(){
  vector<float> ret; //   a->0 ....z->25  Sum of all numbers should be 1
  unsigned int counts[26];
  // Initialize counts to 0
  for(int i = 0; i < 26; i++){
    counts[i] = 0;
  }
  // Step through the document and increment the count if a letter
  for(unsigned int i = 0; i < text.length(); i++){
    if(text[i] >= 'a' && text[i] <= 'z'){
      counts[text[i] - 'a']++;
    }else if(text[i] >= 'A' && text[i] <= 'Z'){
      counts[text[i] - 'A']++;
    } 
  }
  // Run through and get the total count
  int total_count = 0;
  for(int i = 0; i < 26; i++){
    total_count += counts[i];
  }
  // Walk through counts and push-back elements onto the vector
  for(int i = 0; i < 26; i++){
    ret.push_back(static_cast<float>(counts[i]) / static_cast<float>(total_count));
  }
  
  return ret;
}
  
string Book::getText(){
  return text;
}
