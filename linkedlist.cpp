#include <iostream>
using namespace std; 

class linkedlist{
public:
	struct Node{
		int data; 
		Node* next; 
	};

	linkedlist(){
		head = NULL;
	}

	void insert(int val){
		Node *n= new Node();
		n->data = val;
		n->next = head; 
		head = n; 
	}

	void addToEnd(int val){
		Node *n = new Node();
		Node *temp;
		temp=head;
		n->data = val;
		n->next = NULL;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next = n;
	}

	void display(){
			Node *temp; 
			if(head==NULL){
				cout<<"empty";
			}
			temp = head;
			while(temp->next!=NULL){
				cout<<temp->data<<"   "; 
				temp = temp->next; 
			}
			cout<<temp->data<<"   "; 	
	}

	void deleteval(int val){
			Node *temp; 
		    Node *prev;
			if(head==NULL){
				cout<<"empty";
			}
			if(head->data= val){
				head=head->next;
			}
			temp = head->next;
			prev = head;
		 while(temp->next!=NULL){
			if(temp->data==val){
				prev->next= temp->next;
				break;
			}
			prev = prev->next; 
			temp=temp->next;
		}
			if(temp->data==val){
				prev->next= NULL;
			}		
	}

	void pop(){
		head=head->next; 
	}



private:
	Node* head; 
};


int main(){
	linkedlist list; 
	list.insert(5);
	list.insert(10);
	list.insert(15);
	list.insert(20);
	list.insert(14);
	list.display();
	cout<<endl;
	//list.deleteval(14);
	list.addToEnd(200);
	//list.pop();
	list.insert(22);
	list.display();

	return 0; 
}
