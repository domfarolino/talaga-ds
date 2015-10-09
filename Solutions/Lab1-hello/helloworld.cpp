

#include <iostream>
#include <string>

#include <stdlib.h>
#include <stdio.h>
#include "unistd.h"

using namespace std;

// Global 
struct global_args_t {
    int times;
    bool numbers;
    string name;
} global_args;

void displayUsage(){
	
	cout << "./hello [OPTIONS]\n";
	cout << " -n <name>   Hello <name>!\n";
	cout << " -t <int>    repeat Hello.... int times with a count.\n";
	cout << " -h  display usage\n\n";
}


int main(int argc, char **argv){
	// defaults
  global_args.numbers = false;
  global_args.times = 1;
  global_args.name = "World";

	
	int opt = 0;
	extern char *optarg;
	static const char* opt_string = "n:t:";
	opt = getopt( argc, argv, opt_string);
	while(opt != -1){  
		switch(opt){
			case 'n':
				global_args.name = string(optarg);
				break;
			case 't': 
				global_args.numbers = true;
				global_args.times = atoi(optarg);
				break;
			default:
				displayUsage();
				return 0;
		}
		opt = getopt( argc, argv, opt_string);	// Pull the next parameter, or 0 if none.
	}
  
  for(int i = 0; i < global_args.times; i++){
    if(global_args.numbers){
      cout << "[" << i + 1 << "] ";
    }
    cout << "Hello " << global_args.name << "!" << endl;
  }
  
	return 0;
}
