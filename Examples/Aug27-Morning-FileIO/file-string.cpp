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

int main(){

  ifstream instream;
  instream.open("MobyDick.txt", ios::in);

  string the_input;
  int counter = 0;
  while(instream){
    instream >> the_input;
    cout << counter << ":" << the_input << endl;
    counter++;
  }
  
  instream.close();
  return 0;
}
