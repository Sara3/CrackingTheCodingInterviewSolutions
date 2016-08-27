/*
Key, Sara
value, phone #
Hash function -> key (avaluate) -> index
Hash (key) - >index
Hash (sara) -> 3

chaining 

*/

#include <iostream>
#include <cstdlib>
#include <string> 


#include "hash.h"
#include "hash.cpp"

using namespace std; 


int main(){

	hash hashObj; 
	int index;
	index = hashObj.Hash("Sarasd");
	cout<<"index = "<<index; 

	return 0;
}