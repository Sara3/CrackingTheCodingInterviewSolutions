#include <iostream>
//#include <unordered_set>
using namespace std; 

class linkedlist{
public:
	struct Node{
		int data; 
		Node *next;
	};
	linkedlist (){
		head = NULL;
	}
	void insert(int data){
		Node *n = new Node();
		n->data =data; 
		n->next = head;
		head = n;
	}
	void display(){
		Node *temp = new Node();
		temp = head;  
		while(temp->next != NULL){
			cout<<temp->data<<"  ";
			temp = temp->next;
		}
		cout<<temp->data;
	}
	/*
	//extra buffer -- works with C++ 11 or above because of unordered_set
	void removeDup(){
		Node *temp = new Node(); 
		temp = head;
		unordered_set<int> myset(5); 

		while(temp->next!= NULL){
			myset.insert(temp->data);
			temp=temp->next;
		}
		myset.insert(temp->data);
		unoredered_set<int>::iterator it;
	    for (it=myset.begin(); it!=myset.end(); ++it)
		    std::cout << ' ' << *it;
	}
*/ //no extra buffer
	void removeDup(){
		Node *temp = new Node(); 
		temp = head;

		while(temp->next!= NULL){
			Node *runner = new Node();
			runner = temp;
			while(runner->next!=NULL){
				if(runner->next->data==temp->data){
					runner->next= runner->next->next;
				}else{
					runner= runner->next; 
				}
			}
			temp=temp->next;
		}
		temp->data;
		
	}

private:	
	Node *head; 
};

int main(){
	linkedlist list;
	list.insert(5);
	list.insert(10);
	list.insert(5);
	list.insert(8);
	list.insert(9);
	list.removeDup();
	list.display();

}
