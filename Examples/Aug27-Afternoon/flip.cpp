/*
	Example showing how to flip the case of text, with a random probability.
	This is hurridly written in class.  See Examples/flip.cpp for a cleaner version.
	Paul Talaga
	August 2015
*/

#include <iostream>
#include <fstream>
#include <string>

#include <stdlib.h>
#include <stdio.h>
#include "unistd.h"

using namespace std;

char convert(char character){
  if(rand()  % 2 == 0){
    return character;
  }
  if(character >='A' && character <= 'Z'){
    return character - 'A' + 'a';
  }
  if(character >='a' && character <= 'z'){
    return character - 'a' + 'A';
  }
  return character;
}

int main(int argc, char** argv){  
	
	ifstream myfile;
	myfile.open("MobyDick.txt", ios::in);
		
	char character;
	while(myfile){
    myfile.get(character);
    cout << convert(character);
  }
  
  if(something){ convert(lkjlk);
    somethingelse(tkds);
  }
  bla(lkjsdf);
  
  myfile.close();

	
	
	
	
	return 0;
}
