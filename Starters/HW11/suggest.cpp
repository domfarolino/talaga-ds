/*
	Text Suggestion system!   Very much alpha and not documented well!
	Paul Talaga
	November 2015
*/

#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <dirent.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <termios.h>           
#include <unistd.h>    

#include "Prefix.h"

using namespace std;

string getFile(string file_name){
  string ret;
  // Read the file!
  fstream file;
  file.open(file_name.c_str(), ios::in);
  if(file){ // Must have opened fine
    while(file){
      string line;
      getline(file,line);
      ret.append(line + " ");
    }
    file.close();
  }
  return ret;
}


void addSnippets(const string& document, Prefix& p, int num_chars){
  for(unsigned int i = num_chars; i < document.size(); i++){
    p.insert(document.substr(i,num_chars));
  }
}

string lastNWords(string sentence, int num_chars){
  int start = 0;
  if((int)sentence.length() - num_chars > 0){
    start = (int)sentence.length() - num_chars;
  }
  return sentence.substr(start, num_chars);
}

int main(int argc, char* argv[]){
  // Make sure they gave us a folder
  if(argc != 2){
    cout << "Enter file on command-line\n";
    return 1;
  }
  
  string files =  getFile( string(argv[1])); 
  // Generage snippets of length 5
  Prefix snippets;
  addSnippets(files, snippets, 20);
  /*for(unsigned int i = 0; i < words.size(); i++){
    cout << i << ":" << words[i] << "-"<< endl;
  } */
  cout << "Number of snippets: " << snippets.getNumStored() << endl;
  string start = "";
  // Manipulate the terminal to get characters without enter
  // http://stackoverflow.com/questions/1798511/how-to-avoid-press-enter-with-any-getchar
  static struct termios oldt, newt;
  tcgetattr( STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr( STDIN_FILENO, TCSANOW, &newt);
  
  cout << "Enter letters, or @ to exit\n\n";
  char new_char = ' ';
  while(new_char != '@'){  // Excape if @ is typed
    cout << start;
    new_char = getchar();
    if(new_char == 127){  // delete
      start = start.substr(0, start.length()-1);
    }else{
      start = start + new_char;
    }
    if(start.length() > 2){
      string lasts = lastNWords(start, 6);
      cout << endl;
      vector<string> finishes = snippets.getWPrefix(lasts);
      for(unsigned int i = 0; i < min((unsigned int)30, finishes.size()); i++){
        // indent to match
        int indent = (int)start.length() - (int)lasts.length();
        indent = indent % 80;
        for(int j = 0; j < indent; j++){
          cout << " ";
        }
        cout  << finishes[i] << endl;
      }
    }else{
      cout << endl;
    }
  }
  // Repair settings
  tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
  return 0;
}
