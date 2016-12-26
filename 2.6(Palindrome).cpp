#include <iostream>
using namespace std; 

class linkedList{
public:
	struct Node{
		int data; 
		Node* next; 
	};

	linkedList(){
		head = NULL;
	}
	//copy constractor
	linkedList(const linkedList& a){
		head = NULL;
		*this = a;
	}

	//copy assignment Operator
	linkedList& Operator=(const linkedList& a){
		if(a!=this){
			Node* temp = head;
			while(temp->next!=NULL){
				head= head->next;
				delete temp;
				temp = head;
			}
		}
		temp = a.head;
		while(temp!=NULL){
			a.insert(temp->data);
		}
		return *this;

	}

	void insert(int val){
		Node* n = new Node();
		n->data = val; 
		n->next = head;
		head = n;
	}

	void display()const{
		Node* n;
		n= head;
		while(n!=NULL){
			cout<<n->data;
			n=n->next;
		}
	}

	~linkedList(){
		Node* cur; 
		Node* temp; 
		cur=head;  
		while(cur!=NULL){
			temp = cur; 
			cur = cur->next; 
			delete temp;
		}
		delete cur;
	}

private: 
	Node* head; 

};


int main(){
	linkedList a;
	a.insert(3);

	a.display();

}