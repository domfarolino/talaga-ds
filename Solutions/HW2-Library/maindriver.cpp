/*
	Library driver file for the Book and Library classes
	Paul Talaga
	August 2015
*/

// DO NOT CHANGE THIS FILE, OTHER THAN TO COMMENT OUT SECTIONS
#include <string>
#include <iostream>

#include "Library.h"

using namespace std;


int main(){

  // Test giving book title, author,and text as strings.
  Book a("Short Book", "Billy", "Bob",
    "This is the test book!\nWith two lines!");
  cout << "Title: " << a.getTitle() << endl;
  cout << "Full Author: " << a.getFullAuthor() << endl;
  cout << "Author First Name: " << a.getAuthorFirst() << endl;
  cout << "Author Last Name: " << a.getAuthorLast() << endl;
  cout << "Character count: " << a.getCharacterCount() << endl;
  cout << "Line count: " << a.getLineCount() << endl;
  cout << "'the' count: " << a.getWordCount("the") << endl;
  cout << "Book contents: " << a.getText() << endl << endl;
  
  // Test giving a file to open
  Book b("Books/MobyDick.txt");
  cout << "Title: " << b.getTitle() << endl;
  cout << "Full Author: " << b.getFullAuthor() << endl;
  cout << "Author First Name: " << b.getAuthorFirst() << endl;
  cout << "Author Last Name: " << b.getAuthorLast() << endl;
  cout << "Character count: " << b.getCharacterCount() << endl;
  cout << "Line count: " << b.getLineCount() << endl;
  cout << "'the' count: " << b.getWordCount("the") << endl;
  cout << "Book contents: " << b.getText() << endl;
  
  
  // Create a Library and operate on it
  // For HW
  //  Uncomment to test HW assignment
  Library lib("Books/");
  cout << "Book Count: " << lib.getBookCount() << endl;
  cout << "Titles loaded:" << endl;
  vector<string> books = lib.getBookTitles();
  for(unsigned int i = 0; i < books.size(); i++){
    cout << " " << i << ": " << lib.getBook(i)->getTitle()<< "-"  << endl;
  }
  cout << endl;
  
  // Get Macbeth
  Book* first = lib.getBook("Macbeth");
  // Print out the similarity with all others
  for(unsigned int i = 0; i < books.size(); i++){
    cout << " " << i << ": ";
    cout <<  lib.getSimilarity(first, lib.getBook(i)) << " -> " ;
    cout << lib.getBook(i)->getTitle() <<endl;
  }
  
  return 0;
}
