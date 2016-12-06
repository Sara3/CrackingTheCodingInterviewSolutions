#include <iostream>
using namespace std; 

class stack{
	//create a node struct

public:
	struct Node{
		int data; 
		Node *next; 
	};
	stack(){
		top=NULL;
	}
	~stack(){
		if(top==NULL){
			cout<<"Nothing to clear  ";
		}
		//cout<<"delete should be happening"<<endl;
	}
	void push(int data){
		Node *n = new Node(); 
		n->data = data; 
		n->next = top; 
		top=n;
	}

	int pop(){
		Node *n = new Node();
		n=top; 
		top = top->next->next; 
		return n->data;
	}
	void display(){
		Node *n = new Node();
		n=top; 
		while(n->next!=NULL){
			cout<<n->data<<endl;
			n=n->next; 
		}
		cout<<n->data<<endl;
	}

private:
	Node *top; 

};
int main(){
	stack s; 
	s.push(5);
	s.push(12);
	s.push(4);
	s.push(3);
	//int l = s.pop();
	//cout<<l<<endl;
	s.display();
	//delete s;

	return 0; 
}