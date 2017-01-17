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
		}
	}

	void pop(){
		size--;
		head=head->next;
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
/*
class myQueue{
public:
	stack back;
	stack front; 

	void push(int val){
		back.push(val);

	}
	
	void pop(){
		front.clear();
		while(!back.isEmpty()){
			front.push(back.peek());
		 	back.pop();
		 }
		front.pop();
	}

	void display(){
		front.display();
	}

};
*/
int main(){
	stack a;
	a.push(1);
	a.push(2);
	a.push(3);
	//a.pop();
	a.display();

	return 0; 
}