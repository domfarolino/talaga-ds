/*
	Library driver file for the Book class
	Paul Talaga
	August 2015
*/

#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "Book.h"

using namespace std;



void assert(bool thing){
  if(!thing){
    cout << "ASSERT FAILED!\n\n";
    ofstream out;
    out.open("OUTPUT", ios::out);
    out << "false\n";
    out.close();
    exit(0);
  }
}

void assert(string one, string two){
  assert(one.compare(two) == 0);
}

void assert(int input, int desired, int sway){
  assert(input >= desired - sway && input <= desired + sway);
}

void ok(){
  cout << "All OK!\n";
  ofstream out;
  out.open("OUTPUT", ios::out);
  out << "true\n";
  out.close();
  exit(0);
}

int main(int argc, char** argv){

  if(argc != 2){
    cout << "Need a numeric parameter as first argument\n";
    return 1;
  }
  
  int test = atoi(argv[1]);
  cout << "Testing: " << test << endl;
  
  if(test == 0){ // getTitle
    Book a("Short Book", "Billy", "Bob",
    "This is the test book!\nWith two lines!");
    assert(a.getTitle(),"Short Book");
    
    Book b("Short", "Billy", "Bob",
    "This is the test book!\nWith two lines!");
    assert(b.getTitle(), "Short");
    
  }else if(test == 1){ // getFullAuthor
    Book a("Short Book", "Billy", "Bob",
    "This is the test book!\nWith two lines!");
    assert(a.getFullAuthor(),"Billy Bob");
    
    Book b("Short", "Billy", "Bob2",
    "This is the test book!\nWith two lines!");
    assert(b.getFullAuthor(),"Billy Bob2");
    
  }else if(test == 2){ // getAuthorFirst
    Book a("Short Book", "Billy", "Bob",
    "This is the test book!\nWith two lines!");
    assert(a.getAuthorFirst(),"Billy");
    
    Book b("Short", "Billy2", "Bob2",
    "This is the test book!\nWith two lines!");
    assert(b.getAuthorFirst(),"Billy2");
    
  }else if(test == 3){ // getAuthorLast
    Book a("Short Book", "Billy", "Bob",
    "This is the test book!\nWith two lines!");
    assert(a.getAuthorLast(),"Bob");
    
    Book b("Short", "Billy2", "Bob2",
    "This is the test book!\nWith two lines!");
    assert(b.getAuthorLast(),"Bob2");
    
  }else if(test == 4){ // getCharacterCount
    Book a("Short Book", "Billy", "Bob",
    "This is the test book!\nWith two lines!");
    assert(a.getCharacterCount(), 38, 2 );
    
    Book b("Short", "Billy2", "Bob2",
    "This is the");
    assert(b.getCharacterCount(), 11, 2 );
    
    Book c("Short", "Billy2", "Bob2",
    "123456789012345678901234567890123456789012345678901234567890");
    assert(c.getCharacterCount(), 60, 2 );
    
  }else if(test == 5){ // getLineCount
    Book a("Short Book", "Billy", "Bob",
    "This is the test book!\nWith two lines!");
    assert(a.getLineCount(), 2, 1 );
    
    Book b("Short", "Billy2", "Bob2",
    "This is the");
    assert(b.getLineCount(), 1, 0 );
    
    Book c("Short", "Billy2", "Bob2",
    "1234567890\n1234567890\n1234567890\n1234567890\n1234567890\n1234567890");
    assert(c.getLineCount(), 6, 1 );
    
  }else if(test == 6){ // getWordCount
    Book a("Short Book", "Billy", "Bob",
    "This is the test book!\nWith two lines!");
    assert(a.getWordCount("test") == 1);
    
    Book b("Short", "Billy2", "Bob2",
    "This is the is anotheris");
    assert(b.getWordCount("is") == 2);
    
    Book c("Short", "Billy2", "Bob2",
    "This blam haha");
    assert(c.getWordCount("am") == 0);
    
  }else if(test == 7){ // getText
    Book a("Short Book", "Billy", "Bob",
    "This is the test book!\nWith two lines!");
    assert(a.getText().length(), 38, 2);
    
    Book b("Short", "Billy2", "Bob2",
    "This is the is anotheris");
    assert(b.getText().length(), 23, 2);
    
    Book c("Short", "Billy2", "Bob2",
    "This blam haha");
    assert(c.getText().length(), 14, 2);
    
    Book d("Short", "Billy2", "Bob2",
    "This blam haha");
    assert(d.getText().compare("This blam haha") == 0);
    
  }else if(test == 8){ // File loading
    Book a("MobyDick.txt");
    assert(a.getTitle(), "Moby Dick");
    
    Book b("MobyDick.txt");
    assert(b.getAuthorLast(), "Melville");
 
  }
  
  ok();

  return 0;
}
