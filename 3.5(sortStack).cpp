#include <iostream>
using namespace std; 

class stack{
public:
	int size =0;
	struct Node{
		int data; 
		Node *next; 
	};
	stack(){
		head = NULL;
	}

	void push(int val){
		size++;
		Node* n = new Node(); 
		n->data=val; 
		n->next = head; 
		head = n;
	}
	
	void display(){
		Node *n;
		n=head;
		while(n!=NULL){
			cout<<n->data;
			n=n->next;
			cou<<endl;
		}

	}

	int pop(){
		size--;
		Node *n;
		n=head;
		head=head->next;
		return n->data;
	}

	int peek(){
		return head->data;
	}
	bool isFull(){
		return capacity==size;
	}
	bool isEmpty(){
		return size==0;
	}
	void clear(){
		Node *n;
		n=head;
		while(head!=NULL){
			head=head->next;
			delete n; 
		}
	}

private:
	Node* head;
	int capacity=10;


};

int main(){

	stack a;
	a.push(3);
	a.push(4); 
	a.push(1);
	a.push(7);
	a.push(2);
	stack b; 
	int elem;
	while(!a.isEmpty()){
		elem = a.pop();
		while(!b.isEmpty() && elem <b.peek()){
			a.push(b.pop());
		}
		b.push(elem);
	}

	//a.display();
	b.display();

	return 0;
}