#include <iostream> 
#include <cstdlib>
using namespace std; 
/*
This progrram creats a binary search tree and 
and search a given element in it


*/


class node
{
	public:
		int val;
		node* right,* left;
};

void insert(node**tree, node * item)
{
	if(!(*tree))
	{
		*tree = item;
		return;
	}
	if(item->val<(*tree)->val)
	{
		insert(&(*tree)->left, item);
	}
	else if(item->val>(*tree)->val)
	{
		insert(&(*tree)->right, item);
	}
}

bool isPresent(node*_root, int _x)
{
	if(_root==NULL)
	{
		return false;
	}
	else if(_root->val==_x)
	{
		//found the match!
		return true;
	}
	
	else if(_x<=_root->val)
	{
		//if small, the item should be in the left side, pass left
		return isPresent(_root->left, _x);

	}
	else 
	{
		//look in the right branch, pass the right root
		return isPresent(_root->right, _x);

	}
}

int main()
{
	cout<<"Enter the size of the tree  followed by its elements :  "<<endl;
	node * _root, *root_curr;
	int root_i=0, root_cnt =0, root_num =0; 
	_root = NULL;
	
	cin>>root_cnt;//number of nodes in the tree
	
	for(root_i = 0; root_i < root_cnt; root_i++)
	{
		scanf("%d", &root_num);//cin

		root_curr = (node *)malloc(sizeof(node));//create new node

		root_curr ->left = root_curr->right = NULL; //set left right to NULL
		root_curr ->val= root_num; // set the data to root num
		insert(&_root, root_curr);
	}

	cout<<"Enter the element you want search for :  ";
	int _x;
	cin>>_x;
	if(isPresent(_root, _x))
	{
		cout<<"Found!"<<endl;
	}
	else
	{
		cout<<"Not found"<<endl;
	}
	return 0; 
}