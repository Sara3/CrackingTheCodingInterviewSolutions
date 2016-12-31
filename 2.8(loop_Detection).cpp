#include <iostream>
using namespace std; 

class linkedlist{
public:
	struct node
	{ 
		int val;
		node* next;
	};
	linkedlist(){
		head = NULL;
	}

	void insert(int data){
		node * n = new node();
		n->val = data;
		n->next = head;
		head = n;

	}

	void display(){
		node *n = head; 
		while(n!=NULL){
			cout<<n->val; 
			n=n->next;
		}
	}

	node* loopDetection(){
		node* fast = head; 
		node* slow = head;
		node* cir = new node();
		while(fast->next->next!=NULL){
			if(fast==slow){
				cir = fast;
				return cir;
			}

			fast=fast->next->next; 
			slow= slow->next;
		} 
		throw invalid_argument("Does not have a circle "); 
		return cir;
	}


//private:
	node* head; 

};

int main(){
	linkedlist a;
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);
	a.insert(5);
	a.insert(6);
	linkedlist::node * m;
	linkedlist::node * n = new linkedlist::node();
	n->val = 7;
	m=n;
	n->next = a.head;
	a.head = n;
	a.insert(8);
	a.insert(9);
	a.display();
	cout<<endl;
	m->next = a.head;
	a.head = m;
	
	linkedlist::node * loop = new linkedlist::node();
	loop = a.loopDetection();

	cout<<"The loop accures at: "<<loop->val;


	return 0; 
}