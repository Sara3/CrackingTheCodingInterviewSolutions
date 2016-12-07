#include <iostream>
using namespace std; 

class linkedlist{
public:
	struct Node{
		int data;
		Node* next; 
	};
	linkedlist(){
		head=NULL;
	}

	void insert(int val){
		Node *n = new Node();
		n->data = val; 
		n->next = head;
		head=n; 
	}

	void display(){
		Node* n = new Node(); 
		n= head; 
		while(n->next!=NULL){
			cout<<n->data<<"  ";
			n=n->next;
		}
		cout<<n->data<<"   ";
	}

	void deleteThisEl(Node* n){
		n->data=n->next->data;
		n->next = n->next->next;
	}

	void partition(int x){
		Node* slow = new Node(); 
		Node* fast = new Node(); 
		slow= head; 
		fast=slow->next;
		while(fast->next!=NULL){
			if(fast->data<x){
				insert(fast->data);
				deleteThisEl(fast);
			}else{
				slow=slow->next;
				fast=slow->next;
			}
		}
		if(fast->data<x){
			insert(fast->data);
			slow->next=NULL;
		}
	}

private:
	Node* head; 
};

int main(){
	linkedlist s; 
	
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(5);
	s.insert(6);
	s.display();
	cout<<endl;
	s.partition(4);
	s.display();
	
	return 0; 
}