

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include "unistd.h"

using namespace std;


void displayUsage(){
	
	cout << "Usage: caesar -r <int> [OPTION} .. \n" <<endl;
	cout << "-r <int> Rotation amount, positive or negative." <<endl;
	cout << "-f <filename>" <<endl;
	cout << "-? Print help" <<endl;
}

char caesar(char c, int r)
{
  if(isalpha(c))
  {
    if(islower(c))
    {
      c = (((c-97)+r)%26)+97; // 97 is a value of 'a'
    }
    else if(isupper(c))
    {
      c = (((c-65)+r)%26)+65; // 65 is a value of 'A'
    }
  }
  return c;
}


int main(int argc, char **argv){

  string text;
  char* input_file_name;
  int rotation;
  bool have_rotation = false;
  bool have_input_file_name = false;
  

	
	int opt = 0;
	extern char *optarg;
	static const char* opt_string = "r:f:";
	opt = getopt( argc, argv, opt_string);
	while(opt != -1) 
	{  
		switch(opt)
		{
			case 'r':
				have_rotation = true;
				rotation = atoi(optarg);
				break;
			case 'f':
				have_input_file_name = true;
				input_file_name = optarg;
				break;
			default:
			  displayUsage();
			  return 1;
		}
		opt = getopt( argc, argv, opt_string);	
	}
	
	if(!have_rotation)
	{
	  displayUsage();
	  return 0;
	}
	  
	if(have_rotation)
	{
	  if(have_input_file_name)
	  { 	
	    ifstream file(input_file_name);
	    string temp;
	    string text2;
	    while(!file.eof())
	    {
	      getline(file, temp);
	      text2 += temp;
	      text2 += "\n";
	    }
	    text = text2.substr(0,text2.length()-1); // delete the last new line char
	  }
	  else
	  {
	  cout <<"Enter text:"<<endl;
	  getline(cin, text);
	  }
	}
	
	if(rotation < 0)
	{
	  rotation = rotation + 26;
	}
	 	
	string output = "";
	for(size_t i = 0; i < text.length(); i++)
	{
	  output += caesar(text[i],rotation);
	}
	cout<<output<<endl;
	  
  return 0;
}

