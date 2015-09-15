#include <iostream>
#include <vector>
#include <string>

#include "OurContainer.h"

using namespace std;


int main(){

  
  
  //vector<string> a;
  OurContainer<OurContainer<string>*> a;
  OurContainer<void*> b;
  
  /*a.push_back("talaga");
  a.push_back("paul");
  a.push_back("cat");
  a.push_back("fuzz");
  a.push_back("greg");
  a.push_back("cantaloupe"); 
  a.push_back("fubar"); */
  
  a.push_back(new OurContainer<string>);
  a.at(0)->push_back("dog");
  a.at(0)->push_back("pig");
  
  a.push_back(new OurContainer<string>);
 /* a.at(-1)->push_back("cake");
  a.at(-1)->push_back("pie");
  a.at(-1)->push_back("lie");
  
  a.push_back(new OurContainer<string>);
  a.at(-1)->push_back("cake");
  a.at(-1)->push_back("pie");
  a.at(-1)->push_back("lie"); */
  
  // pop_back()
  
  cout << "size: " << a.size() << endl;
  
  for(unsigned int i = 0; i < a.size() ; i++){
    OurContainer<string>* line = a.at(i);
    for(unsigned int j = 0; j < line->size(); j++){
      cout << i << "-" << j << line->at(j) << " ";
     }
     cout << endl;
  }
}
