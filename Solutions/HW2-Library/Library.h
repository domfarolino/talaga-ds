#ifndef LIBRARY_H
#define LIBRARY_H



#include <string>
#include <vector>

#include "Book.h"

using namespace std;

class Library{

  public:
  Library(string folder); // include trailing / in filename
  
  ~Library();   // Class destructor
  
  int getBookCount(); // return the number of books in the library
  
  vector<string> getBookTitles(); // return all the titles of the books
  
  Book* getBook(unsigned int i);  // return a pointer to the book at index i
  Book* getBook(string title);  // return a pointer to the book with title
  
  float getSimilarity(Book* one, Book* two); // return the average difference between
      // the two book's letter percent results

  private:

  vector<Book*> books;  // MUST use a vector of book pointers
  
  // TODO: include anything else you want
  
};


#endif
