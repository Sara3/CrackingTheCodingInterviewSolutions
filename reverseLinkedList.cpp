#include <iostream>
#include <math.h> 
#include <forward_list>
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


	void display(){
			Node *temp; 
			if(head==NULL){
				//cout<<"empty"; prob
			}else{
				temp = head;
				while(temp!=NULL){
					cout<<temp->data<<"   "; 
					temp = temp->next; 
				}
		
			}	
	}

	void reverse(linkedlist &a){
		Node* prev = NULL;
		Node* cur = head; 
		Node* next; 

		while(cur!=NULL){
			next = cur->next;
			cur ->next= prev; 
			prev = cur;
			cur = next; 
		}
		head= prev;
	}

	void reversess(linkedlist &a){	
		Node* prev = NULL; 
		Node* cur; 
		Node* next;
		cur=head;
		while(cur!= NULL){
			next = cur->next;
			cur ->next= prev;
			prev = cur;
			cur=next;
		}
		head = prev; 

	}
private:
	Node* head; 
};

int main(){
	linkedlist a;
	a.insert(7);
	a.insert(5);
	a.insert(1);
	a.insert(2);
	a.insert(0);
	a.display();
	cout<<endl;
	a.reverse(a);
	a.display();


	return 0;
}