#include <iostream>
#include <vector>
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
	
	int kthElement(int k){
		Node *temp = new Node(); 
		temp = head;
	
		vector<int> count; 
		while(temp->next!= NULL){
			count.push_back(temp->data);
			temp=temp->next;
		}
		count.push_back(temp->data);

		return count[count.size() - (count.size()-k)-1];
		
	}

	void printK(int K){

		if(head==NULL){
			cout<<"empty";
		}

		Node* first; 
		Node* second; 
		first = head; 
		second = head;
		int count =0; 
		int count2 =0;

		while(first->next!=NULL){
			count++;
			if(count>=K){
				second=second->next; 
				count2++;
			}

			first= first->next;
			//second=second->next; 
		}
		second = head;
		for(int i=0; i<count-count2; i++){


			second=second->next;
		}
		cout<<second->data;
	}
private:	
	Node *head; 
};

int main(){
	linkedlist list;
	int k=3;
	int n=0;
	list.insert(5);
	list.insert(10);
	list.insert(5);
	list.insert(8);
	list.insert(9);
	n= list.kthElement(k);
	cout<<n;
	cout<<endl;
	list.printK(k);


}
