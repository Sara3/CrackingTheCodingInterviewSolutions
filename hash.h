#include <iostream>
#include <cstdlib>
#include <string> 

using namespace std;


#ifndef HASH_H
#define HASH_H

class hash{
private:
	static const int tablesize = 10;
	struct item{
		string name;
		string drink;
		item* next;
	};
	item* HashTable[tablesize];
public:
	hash();
	int Hash(string key); //string -> avalute -> output.index
	void AddItem(string name, string drink);
	
};


#endif