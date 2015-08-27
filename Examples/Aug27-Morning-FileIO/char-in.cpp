/*
Quick demo for showing how cin behaves with a character.

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

  cout << "hi" << 56 << endl;
  char the_input;
  int counter = 0;
  while(cin){
    cin >> the_input;
    cout << counter << ":" << the_input << endl;
    counter++;
  }
  return 0;
}
