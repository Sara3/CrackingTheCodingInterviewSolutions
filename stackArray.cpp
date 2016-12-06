#include <iostream>
using namespace std; 

class stack{
public:
	stack(){
		top=-1;
	}
	void push(int data){
		top++; 
		a[top] = data; 
	}

	int pop(){
		int n = top; 
		top--;
		return a[n];
	}

	void display(){
		for(int i=0; i<=top; i++){
			cout<<a[i]<<" ";
		}
	}

private:
	int a[1000] ;
	int top;

};

int main(){
	stack s; 
	s.push(5);
	s.push(10);
	s.push(15);
	s.display();
	cout<<endl;
	int l= s.pop();
	cout<<l<<endl;
	s.display();

	return 0; 
}
