//used when you use the memory in heap in new 
#include <iostream>
#include <string>
using namespace std;

class Gcharacter {
	friend ostream&operator<<(ostream& os, Gcharacter& gc);
public:
	static const int DEFAULT_CAPACITY=5;
	//constractor
	Gcharacter(string name = "Sara", int capacity = DEFAULT_CAPACITY);
	//cpy constractor
	Gcharacter (const Gcharacter& source); 
	//over loaded assignment
	Gcharacter& operator = (const Gcharacter& source);
	//destractor
	~Gcharacter();
};