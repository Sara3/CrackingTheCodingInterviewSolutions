#include <iostream>
#include <vector> 
#include <list>
#include <cstdlib>
using namespace std; 

//read up on this some times 
/*
#define ROW 6
#define COL 6
class Matrix{
public:
	Matrix(){}

	void addEdge(int v1,int v2){
		if(v1>=0 && v1<ROW && v2>0 && v2< COL){
				v[v1][v2]=1;
				v[v2][v1]=1;

			}
	}

	void removeEdge(int v1, int v2){
		if(v1>=0 && v1<ROW && v2>0 && v2< COL){
				v[v1][v2]=0;
				v[v2][v1]=0;
		}
	}
	void isEdge(int v1, v2){
		if(int v1>=0 && v1<ROW && v2>0 && j< COL){
			return v[v1][v2];
		}
		return false;
	}


	void display(){
		for(int i=0; i<ROW; i++){
			for(int j=0; j<COL; j++){
				cout<<v[i][j]<<' ';
			}
			cout<<endl;
		}
	}
 
private:
	int v [ROW] [COL] = {{0}};

};



class AdjacencyList{
public:

AdjacencyList(){
	for(int i=0; i<5; i++){
		vector<int> v;
		list.push_back(v);
	}
}

 
void add(int a, int b){
	list[a].push_back(b);
	list[b].push_back(a);
}
void display(){
	for(int i=0; i<list.size(); i++){
		for(int j=0; j<list[i].size(); j++){
			cout<<list[i][j]<<" ";
		}
		cout<<endl;
	}
}

private:

vector<vector<int>>list; 

};

//Anjacency list node
struct Node{
	int dest;
	Node *next;
};
//Adjacency list
struct Adjlist{
	struct Node *head;
};
//class Graph
class Graph{
private:
	int v;
	struct Adjlist *array;
public:
	Graph(int l){
		v=l;
		array = new Adjlist[v];//my Adjlist did now get any arguments +
		for(int i=0; i<v; ++i){//+ we dont initialize arrray that way
			array[i].head = NULL;
		}
	}

	//creating new Adjacency lost Node

	Node* newAdjlistNode(int dest){
		Node* newNode = new Node();
		newNode->dest=dest;
		newNode->next = NULL;
		return newNode;
	}
	// Adding Edge to Graph
	void addEdge(int src, int dest){
		Node* newNode = newAdjlistNode(dest);
		newNode->next = array[src].head;
		array[src].head=newNode;
		newNode = newAdjlistNode(src);
		newNode->next = array[dest].head;
		array[dest].head = newNode;
	}

	void printGraph(){
		int i;
		for(i=0; i<v; ++i){
			Node *temp = array[i].head;
			cout<<"Adjacency list vertex "<<i<<endl;
			cout<<"head ";
			while(temp){
				cout<<"->"<<temp->dest;
				temp=temp->next;
			}
			cout<<endl;
		}
	}


};

void printG(int v,adjlist* array){
	Node *n = new Node(); 
	n->data =4; 
	n->next = NULL;
	for(auto i=0; i< v; ++i){
		array[i].head=n;
	} 
	for(int i=0; i<v; i++){
		Node *temp = array[i].head;
		cout<<"Adjacency list for vertex: "<<i<<endl;
		cout<<"head ";
		while(temp!=NULL){
			cout<<"->"<<temp->data<<endl;
			temp=temp->next; 
		}
		cout<<endl;
	}
}

*/

struct Node{
		int data; 
		Node *next; 
	};

class Graph{
public:
	
	Graph(int v){
		V=v; 
		Node *head=NULL;
		array=new Node[v];
		for(auto i=0; i< v; ++i){
			array[i] =head; 
		}
	}

/*
	void printG(){
		
		for(int i=0; i<v; i++){
			Node *temp = array[i];
			cout<<"Adjacency list for vertex: "<<i<<endl;
			cout<<"head ";
			while(temp!=NULL){
				cout<<"->"<<temp->data<<endl;
				temp=temp->next; 
			}
			cout<<endl;
		}
	}
*/


private:
	int V; 
	
	struct Node* array;
};




int main(){
	//int v =4;
	/*
	Node *array[v];
	Node *head = NULL; 

	Node *newNode = new Node(); 
	newNode->data = 2; //3
	 
	for(auto i=0; i< v; ++i){
		array[i] =head; 
	}

	array[3] = newNode;

	for(auto i=0; i< v; ++i){
		cout<<array[i]<<endl; 
	}

	cout<<array[3]->data;

*/

	



	return 0; 
}
