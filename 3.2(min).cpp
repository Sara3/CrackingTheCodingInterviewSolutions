#include <iostream>
#include <climits>
using namespace std; 

class stack{
public:
	struct node
	{
		int data;
		node* next;
		
	};

	struct minimum
	{
		int value;
		minimum *next;
	};

	stack(){
		head = NULL;
		first = NULL; //use bigger see range
	}

	void push(int val){
		node *n = new node();
		n->data = val;
		n->next=head;
		head=n;

		if(first ==NULL || first->value > val){
			minimum *m = new minimum();
			m->value = val;
			m->next = first;
			first = m;
		}else{
			minimum *m = new minimum();
			m->value = first->value;
			m->next = first;
			first = m;
		}
	}
	
	void pop(){
		head=head->next;
		/*
		if(n->data == first->value){
			first = first->next;
		}*/
		first = first->next;

	}
	
	int peek(){
		return head->data;
	}
	bool empty(){
		if(head==NULL) 
			return true;
		return false;
	}
	void dispay() const{
		node *n;
		n=head;
		while(n!=NULL){
			cout<<n->data<<" ";
			n=n->next;
		}
	}
	int min(){
		if(first==NULL){
			return INT_MAX;
		}
		return first->value;
	}
private:
	node *head; 
	minimum *first; 

};

int main(){
	stack a;
	a.push(8);
	a.push(4);
	a.push(7);
	a.push(4);
	a.pop();
	a.dispay();
	cout<<endl;
	cout<<a.min();

	return 0;
}