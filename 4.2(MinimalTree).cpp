#include <iostream> 
#include <vector>
using namespace std; 

class tree{

public:
	struct Node{
		int val;
		Node *left; 
		Node *right; 
	};

	void insert( int val){
		insertNode(head, val);
	}




	void Print()
	{
	   Print1(head);
	}

private:
	void Print1(Node* head)
	{
	    if (head==NULL) return;
	    Print1(head->left);
	    cout << head->val<< endl;
	    Print1(head->right);
	}
    Node* head= NULL;
	void insertNode(Node* root, int val){
		Node *newNode = new Node();
		newNode->val = val; 
		newNode->left = NULL;
		newNode->right = NULL;
		if( root==NULL){
			root= newNode; 
		} else {
			if(val<root->val){
				insertNode(root->left, val);
			} else {
				insertNode(root->right, val);
			}
		}
	}


};



int main(){
	tree B;
	B.insert(20);
	B.insert(1);
	B.insert(2);
	B.insert(30);
	B.insert(50);

	B.Print();


	return 0; 
}