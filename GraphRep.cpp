#include <iostream>
#include <vector> 
#include <list>
#include <cstdlib>
using namespace std; 
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
*/
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
int main(){
	Graph gh(5);
    gh.addEdge(0, 1);
    gh.addEdge(0, 4);
    gh.addEdge(1, 2);
    gh.addEdge(1, 3);
    gh.addEdge(1, 4);
    gh.addEdge(2, 3);
    gh.addEdge(3, 4);

 
    // print the adjacency list representation of the above graph
    gh.printGraph();

	return 0; 
}
