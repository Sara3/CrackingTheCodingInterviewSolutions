#include <iostream>
#include <list>
using namespace std; 
//https://github.com/wzhishen/cracking-the-coding-interview/blob/master/src/chap03/Q7.java
class Wrap{
	class Animal{
	public:
		int timestamp; 
		string name;
		Animal(string n){
			name=n;
			timestamp =0; 
		}
	};

	class Dog: public Animal{
	public:
		Dog(string n){
			Animal(n);
		}
		int time(){
			cout<<"Dog: "<<name;
			return timestamp;
		}
	};

	class Cat: public Animal{
		public:
			Cat(string n){
				Animal(n);
			}
			int time(){
				cout<<"Cat: "<<name;
				return timestamp;
			}
	};

void enqueue(Animal a, char i){
	if(i=='c'){
		cats.push_back(a);
	}else if(i=='d'){
		dogs.push_back(a);
	}
	else{
		throw invalid_argument ("Unknown type of animal!");
	}
}

Dog dequequeDog(){
	Dog temp; 
	if(noDog)
		throw invalid_argument ("Dog isEmpty");
	temp = dogs.front();
	return dogs.pop_front();
}
Cat dequequeCat(){
	Cat temp; 
	if(noCat)
		throw invalid_argument ("Cat isEmpty");
	temp = cats.front();
	return cats.pop_front();
}

    Animal dequeueAny() {
        if (noAnimal()) {
            throw invalid_argument("No animals!");
        } else if (noDog()) {
            return dequeueCat();
        } else if (noCat()) {
            return dequeueDog();
        } else if (peekDog().timestamp < peekCat().timestamp) {
            return dequeueDog();
        } else {
            return dequeueCat();
        }
    }

   Dog peekDog() {
        throw invalid_argument ("No Dog");
        return dogs.front();
    }

    Cat peekCat() {
       	throw invalid_argument ("No cat");
        return cats.front();
    }
 	bool noDog() {
        return dogs.empty();
    }

    bool noCat() {
        return cats.empty();
    }

    bool noAnimal() {
        return noDog() && noCat();
    }


private:
	 list<Dog> dogs; 
	 list<Cat> cats;

};
