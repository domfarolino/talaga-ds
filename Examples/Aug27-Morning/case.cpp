/*
Quick demo for changing the case randomly for MobyDick.txt.

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
  if(rand() %2 == 0){
    return character;
  }
  if(character >= 'a' && character <= 'z'){
    return character - 'a' + 'A';
  }
  if(character >= 'A' && character <= 'Z'){
    return character - 'A' + 'a';
  }
  return character;
}

void printCharacter(istream* input){
//  cout << "size: " << sizeof(input) << endl;
  
  char the_input;
  int counter = 0;
   while(*input){
//    cout <<"address: " << input << endl;
    input->get(the_input);
    cout  << convert(the_input);
    counter++;
  }
  return;
}

int main(){
/*

*/
  ifstream instream;
  instream.open("MobyDick.txt", ios::in);
  //instream.open("encrypted.txt", ios::in);

  //printCharacter(&cin);
  printCharacter(&instream);
  
  instream.close();
  return 0;
}
