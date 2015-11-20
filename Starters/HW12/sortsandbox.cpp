/*
	Sort Sandbox
	Paul Talaga
	November 2015
*/

#include <iostream>
#include <stdlib.h>

#include "MySort.h"

using namespace std;

int main(int argc, char* argv[]){

	srand(time(0));
  vector<int> a;
  int s = 30;
	for(int i = 0; i < s; i++){
		a.push_back(rand() % 20);
	}
	for(int i = 0; i < s; i++){
		cout << i << ":" << a[i] << endl;
	}
	//bubbleSort(a);
	//mergeSort(a);
	for(int i = 0; i < s; i++){
		cout << i << ":" << a[i] << endl;
	}
}
