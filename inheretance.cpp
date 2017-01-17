#include <iostream>
using namespace std; 

class person{
public:
	string profession;
	int age;
	person(): profession("unemployed"), age(16){}
	void display(){
		cout<<"My proff: "<<profession<<endl;
		cout<<"My age: "<<age<<endl;
		walk();
	}
	void walk(){
		cout<<"I walk"<<endl; 
		cout<<"I talk"<<endl;
	}
};

class Math: public person{
	public:
		void teachMath(){
			cout<<"teach math"<<endl;
		}
};

class foot: public person{
public:
	void playFootball(){
		cout<<"football"<<endl;
	}
};


int main(){
	Math teacher; 
	teacher.profession = "teacher";
	teacher.age = 23;
	teacher.display();



	return 0;
}