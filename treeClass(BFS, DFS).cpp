#include <iostream>
#include <iomanip>
using namespace std; 
class tree{
public:
	struct Node{
		int key_value;
		Node *left;
		Node *right;
	};
	 tree(){
	 	root==NULL;
	 }
	 ~tree(){
	 	//destroy_tree();
	 }

	 void insert(int key){
	  if(root!=NULL){
	      insert(key, root);
	  }else{
	    root=new Node();
	    root->key_value=key;
	    root->left=NULL;
	    root->right=NULL;
	  }
	 }

	 Node *search(int key){
	 	return search(key, root);
	 }

	 void destroy_tree(){
	  destroy_tree(root);
	}

	void display(){
		display(root);
		}
		
private:
	 Node *root;
	// void display(Node *leaf, int indent =0){
	// 	if(leaf!=NULL){
	// 		cout<<leaf->key_value<<endl;
	// 		cout <<setw(indent) << ' '<<"\\\n";
	// 		display(leaf->left, indent+4);
	// 		display(leaf->right, indent+4);

	// 	}
	// }

	void display(Node *leaf, int indent=0){
		if(leaf!=NULL){
			if(leaf->right){
				display(leaf->right, indent+4);
			}
			if(indent){
				cout<<setw(indent)<<' ';
			}
			if(leaf->right)
				cout<<" /\n"<<setw(indent)<<' ';
			cout<<leaf->key_value<< "\n";
			if(leaf->left){
				cout<<setw(indent)<<' '<<" \\\n";
				display(leaf->left, indent+4);
			}
		}
	}

	void destroy_tree(Node *leaf){
		if(leaf!=NULL){
			destroy_tree(leaf->left);
			destroy_tree(leaf->right);
			delete leaf;
		}
	}
	void insert(int key, Node *leaf){
		if(key< leaf->key_value){
			if(leaf->left!=NULL){
				insert(key, leaf->left);
			}else{
				leaf->left = new Node();
				leaf->left->key_value = key;
				leaf->left->left=NULL;
				leaf->left->right=NULL;
			}
		}
		else if(key>=leaf->key_value){
			if(leaf->right!=NULL){
				insert(key, leaf->right);
			}else{
				leaf ->right = new Node();
				leaf->right->key_value = key;
				leaf->right->left=NULL;
				leaf->right->right=NULL;
			}
		}
	}

	Node *search(int key, Node *leaf){
	if(leaf!=NULL){
	    if(key==leaf->key_value)
	      return leaf;
	    if(key<leaf->key_value)
	      return search(key, leaf->left);
	    else
	      return search(key, leaf->right);
	    }
	    else return NULL;
	}


};

//http://www.cprogramming.com/tutorial/lesson18.html


int main(){
	tree a; 
	a.insert(2);
	a.insert(1);
	a.insert(3);
	a.insert(7);
	a.insert(10);
	a.insert(2);
	a.insert(5);
	a.insert(8);
	a.insert(6);
	a.insert(4);

	a.display();
	

	return 0; 
}