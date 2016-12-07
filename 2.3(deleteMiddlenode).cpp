#include <iostream>
using namespace std; 
class linkedlist{
public:
	struct Node
	{
		int data;
		Node*next; 
	};

	 linkedlist(){
	 	head = NULL;
	 }

	void insert(int val){
		Node*n=new Node();
		n->data=val;
		n->next=head;
		head=n;
	}

	void deleteThisEl(Node* n){
		n->data=n->next->data;
		n->next = n->next->next;
	}

	Node* returnNode(int val){
		Node* n = new Node();
		n=head;
		while(n->next!= NULL){
			if(n->data==val){
				return n;
			}
			n=n->next;
		}
		//cout<<n->data<<endl;
		return n; //we assume that the val def. exists else will return the last node
	}
	void display(){
		Node* n = new Node();
		n=head;
		while(n->next!= NULL){
			cout<<n->data<<" ";
			n=n->next;
		}
		cout<<n->data<<endl;
	}
private: 
	Node*head; 
};

int main()
{

	linkedlist s;
	linkedlist::Node*m;
	m=new linkedlist::Node();
	s.insert(5);
	s.insert(3);
	s.insert(4);
	s.insert(5);
	s.display();
	m=s.returnNode(4);
	s.deleteThisEl(m);
	cout<<endl;
	s.display();


	return 0; 
}

