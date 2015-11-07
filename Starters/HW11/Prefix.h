#ifndef PREFIX_H
#define PREFIX_H
/*
   Trie (Prefix) class for storing and retrieving strings.
   Paul Talaga
   November 2015
 */
 
 #include <string>
 #include <vector>

using namespace std;

const unsigned int B_FACTOR = 27;  // a..z plus space

struct Node_t {
		bool word;
		Node_t* links[B_FACTOR];
	} ;

class Prefix {
	
	public:
	Prefix();
	Prefix(const Prefix &copy);
	Prefix& operator=(const Prefix& other);
	~Prefix();
	
	bool insert(string thing);
	
	int getHeight();
	int getNumNodes();
	int getNumStored();
	vector<string> getWPrefix(string);
	vector<string> getAllStored();
	int getNumWPrefix(string prefix);
	
	bool isStored(string thing);
	
	
	private:
	Node_t *root;
	
	// Hint... fill in functions here!
	
	
};
#endif  
