#include <iostream>
#include <cstdlib>
#include <string> 

#include "hash.h"


using namespace std; 

hash::hash(){
	for(int i=0; i<tablesize; i++){
		HashTable[i] = new item;
		HashTable[i] -> name = "empty";
		HashTable[i] -> drink = "empty";
		HashTable[i] -> next = NULL;
	}
}
void hash::AddItem(string name, string drink){
	int index = Hash(name);

	if(Hash[index]->name == "empty"){
		HashTable ->name = name;
		HashTable ->drink = drink; 
	}
	else
	{
		item* ptr = HashTable[index];
		item*n = new item;
		n->name = name;
		n-> drink = drink;
		n->next = NULL;
		while(ptr ->next !=NULL){
			ptr = ptr->next;
		}
		ptr ->next =n;
	}
}

int hash::Hash(string key) //hash:: comes from hash class
{
	//table size (arr size) -> 100
	int hash =0;
	int index;
	int sum=0;

	for(int i=0; i<key.length(); i++){
		hash = hash+ (int) key[i];
		
	}
	index = hash % tablesize;
	cout<<hash<<endl;


	return index;
}
//part 7 --look