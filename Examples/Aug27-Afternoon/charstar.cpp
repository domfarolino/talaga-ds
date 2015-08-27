/*
	Some ugly char* demo for showing how char* is really a list of characters
	that is null terminated.
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
 char* test = "This is a str";
 //test[10] = 0;
 for(int i = 0; i < 14 ; i++){
  cout << "pos: " << i << " " << test[i] << " is " <<(int)test[i] << endl;
 }
 
 cout << "first: " << *(test+5) << test[5] << endl;
 //test[13] = '!';
 //cout << test << endl;
 
}
