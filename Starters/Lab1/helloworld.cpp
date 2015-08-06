/*
	Hello World
	If -n is given, use the supplied string, otherwise use 'World'.
	If -t is given, repeat the same line that many times with a count. 
	If no -t is given, don't put a number on the line.
	If -h, print help.
	Paul Talaga  // TODO
	July 2015    // TODO
*/

#include <iostream>
#include <string>

#include <stdlib.h>
#include <stdio.h>
#include "unistd.h"

using namespace std;

// Global settings
struct global_args_t {
    // TODO
} global_args;

void displayUsage(){
	// Displays how to use this program
	// TODO
}


int main(int argc, char **argv){
	// defaults
  // TODO

	// process command-line arguement
	int opt = 0;
	extern char *optarg;
	static const char* opt_string = "n:t:";
	opt = getopt( argc, argv, opt_string);
	while(opt != -1){  // While there are parameters to parse, do so
		switch(opt){
			case 'n':
				// TODO
				break;
			case 't': // Caesar cipher rotation amount
				// TODO
			default:
				displayUsage();
				return 0;
		}
		opt = getopt( argc, argv, opt_string);	// Pull the next parameter, or 0 if none.
	}

  cout << "Hello World!\n";
  
	return 0;
}
