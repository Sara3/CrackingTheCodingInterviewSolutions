#include <iostream> 
#include <vector>
#include <stack>
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
private:
	Node* head;
	int capacity=10;


};

class setOfStacks{
	stack<stack> s; 

}; 
/*
class SetsOfStacks{
public:

	SetsOfStacks(int capac){
		capacity = capac;
	}

	stack getLastStack(){
		if(stacks.size()==0) return NULL;
		return stacks[stacks.size()-1];
	}

	void push(int v){
		stack last = getLastStack();
		if(last!=NULL && !last.isFull()){
			last.push(v);
		}else{
			stack Stack = new stack(capacity);
			Stack.push(v);
			stacks.push_back(Stack);

		}
	}

	void pop(){
		stack last = getLastStack();
		if(last==NULL) throw invalid_argument( "Salary must be greater than 0.0" );
		last.pop();
		if(last.size==0 ){//size??
			stacks.remove(stacks.size()-1);
	}
	bool isEmpty(){
		stack last = getLastStack();
		return last == NULL || last.isEmpty();
	}


private:
	vector<stack> stacks;
	int capacity; 
};*/

int main(){
	stack a;
	a.push(1);
	a.push(2);
	a.push(3);
	cout<<a.size<<endl;
//	a.pop();
	//cout<<a.peek();
	a.display();
	if(a.isEmpty() || a.isFull()){
		cout<<"whilte";
	}else{
		cout<<"black";
	}
	return 0;
}

