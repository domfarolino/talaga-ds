/*
Quick demo for showing how get can be used with cin and files.
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

void printCharacter(istream* input){
  cout << "size: " << sizeof(input) << endl;
  
  char the_input;
  int counter = 0;
   while(*input){
    cout <<"address: " << input << endl;
    input->get(the_input);
    cout << counter << ":" << the_input << endl;
    counter++;
  }
  return;
}

int main(){
/*

*/
  ifstream instream;
  instream.open("MobyDick.txt", ios::in);

  //printCharacter(&cin);
  printCharacter(&instream);
  
  instream.close();
  return 0;
}
