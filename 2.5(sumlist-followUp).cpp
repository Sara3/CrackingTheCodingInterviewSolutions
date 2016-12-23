#include <iostream>
#include <math.h> 
#include <stack>

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

	int pop(){
		Node *n ;
		n=head;
		head=head->next; 
		return n->data;
	}
	bool empty(){
		if(head!=NULL){
			return false;
		}
		return true;
	}

	int size(){
		Node* s;
		s= head;
		int size=0;
		while(s!=NULL){
			s=s->next;
			size++;
		}

		return size;
	}

	void samesize(linkedlist &a, linkedlist &b){
		int diff =0; 
		bool aIsBig = false;
		if(a.size()>b.size()){
			aIsBig = true;
			diff = a.size()-b.size();
		}
		else if(a.size()<b.size()){
			diff = b.size() - a.size();
		}
		for(int i=0; i<diff; i++){
			if(aIsBig){
				b.insert(0);
			}else{
				a.insert(0);
			}
		}
	}
	linkedlist add(linkedlist a, linkedlist b){
		stack <int> s;
		linkedlist c;

		Node* temp ;
		Node* temp2 ;
		int sum = 0;
		int carry = 0; 
		temp = a.head;
		temp2 = b.head;
		int lastdig= 0;


		while(temp!=NULL ){
			sum = temp->data+temp2->data;
			s.push(sum);
			temp2=temp2->next;
			temp=temp->next;
		}
		
		while(!s.empty()){
			lastdig = (s.top()+carry);
			carry = (lastdig>9)?1:0;
			lastdig = lastdig%10;
			c.insert(lastdig);
			s.pop();
		}
		

	
		return c;
	}

	/*
	~linkedlist(){
		Node *temp = new Node();
		while (head != NULL)
		{
			temp = head->next;
		    delete head;
		    head = temp;
		}
		delete temp;
	}
*/

private:
	Node* head; 
};



int main(){
	linkedlist a; 
	linkedlist b;
	linkedlist res;
	a.insert(7);
	a.insert(5);
	a.display();
	cout<<endl;
	b.insert(5);
	b.insert(9);
	b.insert(6);
	b.insert(2);
	b.insert(1);
	b.insert(3);
	b.display();
	cout<<endl<<endl;
	a.samesize(a, b);
	res = a.add(a, b);
	res.display();

	

	
	return 0; 
}