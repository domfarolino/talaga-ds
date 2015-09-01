#ifndef BOOK_H
#define BOOK_H

/*
	Inferface for Book class
	Paul Talaga
	August 2015
*/

#include <string>
#include <vector>

using namespace std;

class Book{

  public:
  // Open file to read as book.
  // See instructions for file markup.
  Book(string filename);
  // Provide all parts of book as strings.
  Book(string title, string first, string last, string book);
   
  // Setters
  // No setters.
  
  // Getters
  // Return title
  string getTitle();
  // Return "first last" 
  string getFullAuthor();
  // Return first name of author
  string getAuthorFirst();
  // Return last name of author
  string getAuthorLast();
  
  // Return the number of characters, including all non-printables
  // hint: string length
  unsigned int getCharacterCount();
  // Number of lines in the book - hint: \n
  unsigned int getLineCount();
  // Number of times 'word' is used in the book
  unsigned int getWordCount(string word);
  
  vector<float> letterPercent();  // for HW
  
  // Return the contents of the book
  string getText();

  private:

  string title;
  string first;
  string last;
  string text;
};


#endif
