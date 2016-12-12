#include <iostream>
#include <math.h> 
#include <forward_list>
using namespace std; 
/*
forward_list<int> addlist(forward_list<int> a, forward_list<int> b){
	forward_list<int> c; 
	int sum =0;
	int sum2 =0;
	int total =0;
	int j=0;

	for(int&i:a) {
		sum += i*pow(10,j);
		j++;
	}

	j=0;
	for(int&i:b) {
		sum2 += i*pow(10,j);
		j++;
	}
	total=sum2+sum;

	while (total != 0) {
		c.push_front(total%10);
	    total /= 10;
	}

	for(int&i:c) {
		cout<<i<<" ";
	}
	return c;
}

*/
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
				cout<<"empty";
			}
			temp = head;
			while(temp!=NULL){
				cout<<temp->data<<"   "; 
				temp = temp->next; 
			}	
	}

	int pop(){
		Node *n ;
		n=head;
		head=head->next; 
		return n->data;
	}
	
	linkedlist add(linkedlist a, linkedlist b, int curry){
		linkedlist c; 
		Node *n;
		Node *m;
		n=a.head;
		m=b.head;
		int sum=0;
		while (n!=NULL){
			sum=n->data + m->data+curry;
			c.insert(sum%10);
			curry = sum/10; 
			n=n->next;
		}
		c.insert(curry);
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
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.display();
	cout<<endl;
	b.insert(3);
	b.insert(0);
	b.insert(9);
	b.display();
	cout<<endl<<endl;
	res=res.add(a, b, 0);
	res.display();


	return 0; 
}