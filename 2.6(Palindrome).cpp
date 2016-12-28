#include <iostream>
#include <stack>
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
	/*
	//copy constractor
	linkedList(const linkedList& a):head(a.head){
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
*/
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
	/*
	reverse a linkedlist
	bool isPalindrom(){
		stack<int> s;
		Node* temp = head;
		while(temp!=NULL){
			s.push(temp->data);
			temp= temp->next; 
		}
		//cout<<"stack: "<<endl;
		temp = head;

		while(!s.empty()&&temp!=NULL){
			if(s.top()!=temp->data){
				return false;
			}
			temp= temp->next;
			s.pop();
		}
		return true;
	}
	*/
	bool isPal(){
		Node* fast = head;
		Node* slow = head;
		stack<int> s;
		while(fast!=NULL && fast->next!=NULL){
			s.push(slow->data);
			slow=slow->next;
			fast = fast->next->next;
		}
		while(!s.empty()){
			if(s.top()!=slow->data){
				return false;
			}
			slow = slow->next;
			s.pop();
		}
		//if odd number skip the middle element 
		if(fast!=NULL){
			slow=slow->next;
		}
		return true;
	}
/*
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
*/
private: 
	Node* head; 

};


int main(){
	linkedList a;
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);
	a.insert(5);
	a.insert(6);
	a.insert(7);
	a.insert(8);
	a.insert(9);
	a.insert(10);
	a.display();
	cout<<endl;
	if(a.isPal()){
		cout<<"is Pal"<<endl;
	}else{
		 cout<<"Is not";
	}

	return 0;
}