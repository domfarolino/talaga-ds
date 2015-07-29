/*
	Example showing how to flip the case of text.
	If -f is given, use text from file, otherwise STDIN.
	Paul Talaga
	July 2015
*/

#include <iostream>
#include <fstream>
#include <string>

#include <stdlib.h>
#include <stdio.h>
#include "unistd.h"

using namespace std;

// Global settings
struct global_args_t {
    bool use_file;			/* -f option, use from file */
		string file_name;		// Filename to use
} global_args;

void displayUsage(){
	// Displays how to use this program
	cout << "Usage: flip [OPTION] ..\n\n";
	cout << "-f <filename>\n";
	cout << "-? Print help\n\n";
	cout << "By default and no options, this takes text from standard input\n";
	cout << "and ends when an end-of-file character is given (ctrl-d), and flips\n";
	cout << "the case of the given text.\n";
}

char convertCharacter(const char &character){
	// Returns a converted character.  If it was lowercase, make it uppercase, if it
	// was upper, make it lower, otherwise don't change it.
	if(character >= 'a' && character <= 'z'){
		return character - 'a' + 'A';
	}else if(character >= 'A' && character <= 'Z'){
			return character - 'A' + 'a';
	}else{
		return character;
	}
}

void readStream(istream &file){
	// Read characters from the given stream and print the converted characters to the screen.
	char character;
	// Note we use get here so we are sure to get ALL characters.
	file.get(character);
	while(file){ // This will pull in lines until the stream is exhausted
		cout << convertCharacter(character);
		file.get(character);
	}
}

int main(int argc, char **argv){
	// defaults
	global_args.use_file = false;
	global_args.file_name = "";
	
	// process command-line arguement
	int opt = 0;
	extern char *optarg;
	static const char* opt_string = "f:";
	opt = getopt( argc, argv, opt_string);
	while(opt != -1){  // While there are parameters to parse, do so
		switch(opt){
			case 'f': 
				// The f case from opt_string above has a : after it, meaning take the next
				// thing as optarg.
				global_args.use_file = true;
				global_args.file_name = optarg;
				break;
			default: 
				displayUsage();
				return 0;
		}
		opt = getopt( argc, argv, opt_string);	// Pull the next parameter, or 0 if none.
	}
	
	// File name given
	if(global_args.use_file){
		ifstream instream;
		instream.open(global_args.file_name, ios::in );
		if(instream.fail()){
			cout << "Could not open " << global_args.file_name << endl;
			return 1;
		}
		readStream(instream);
		instream.close();
	}else{ // no file given, use cin
		readStream(cin);
	}
	
	return 0;
}