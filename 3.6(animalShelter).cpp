#include <iostream>
#include <list>
#include <vector>
using namespace std; 

class queue{
public:
	queue(){
		num={-1};
	}
	void enQueue(string v, char n){
		num.push_back(n);
		list.push_front(v);
	}
	string deQueue(){
		auto i= list.back();
		list.pop_back();
		return i; 
	}
	char getnum(){
		return num.back();
	}
	bool empty(){
		return list.empty();
	}
	void deletelast(){
		
	}

private:
	vector<char> num;
   list<string> list; 
};

class animal{
public: 
//enqueue, dequeueAny, dequeueDog and dequeueCat
	animal(){}
void enqueue (string v){
	if(v=="dog" || v=="Dog"){
		dogs.enQueue(v, 'd');
	}else if( v=="cat" || v=="cats"){
		cats.enQueue(v, 'c');
	}else {
		//throw invalide_argument("Please insert correct string");
	}

}
string dequeueCats(){

	return cats.deQueue();

}
string dequeueDogs(){

	return dogs.deQueue();
}
string dequeueAnimal(){
	string m = "could not get the value"; 
	if(dogs.getnum()=='d'){
		return dogs.deQueue();
	}else if(cats.getnum()=='c')
	{
		return cats.deQueue();
	}
	return m;
}

private:
	queue dogs; 
	queue cats; 
	int counter; 
};

int main(){

	animal a; 
	a.enqueue("dog");
	a.enqueue("cat");
	a.enqueue("dog");
	a.enqueue("cat");

	cout<<a.dequeueAnimal();



	return 0;
}