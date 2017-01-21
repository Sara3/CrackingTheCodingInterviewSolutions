#include <iostream>
#include <vector>
#include <stack>
using namespace std; 
/*
//array and can be done with lists 
class Graph{
public:
	Graph(int v){
		V=v;
		array.resize(V);

	}
	void addEdge(int src, int dest){
		array[src].push_back(dest);
	}
	void display(){
		for(int i=0; i<array.size(); i++){
			cout<<"for vertex: "<<i;
			cout<<"   head-> ";
			for(int j=0; j<array[i].size(); j++){
				cout<<array[i][j]<<" ";
			}
			cout<<endl;
		}
	}

private:
	int V;
	vector< vector<int>> array;
};

*/
class GraphN{
public:
	struct Node{
		int data;
		Node *next; 
	};

	struct Adjlist{
		 Node *head;
	};

	GraphN(int vertex){
		V=vertex;
		arr = new Adjlist[V];
		for(auto i=0; i<V; i++){
			arr[i].head = NULL;
		}
	}

	void addEdge(int src, int dest){
		Node *temp =new Node();
		temp->data = dest;
		temp->next=arr[src].head;
		arr[src].head=temp; 

		Node *temp1 =new Node();
		temp1->data =src;
		temp1->next=arr[dest].head;
		arr[dest].head=temp1; 
				
	}

	void DFS(){
		vector<Node>visited;
		stack <Node> s; 
		Node *temp;
		visited.push_back(arr[0].head);
		while(!s.empty()){
			temp=s.top();
			s.pop();
			while(temp!=NULL){
				if (find(visited.begin(), visited.end(),temp)==v.end()){
					s.push(temp);
					visited.push_back(temp);
				}

				temp=temp->next;
			}

		}


	}

	void display(){
		for(auto i=0; i<V; i++){
			Node *temp = arr[i].head;
			cout<<"Adjecency list for vectex: "<<i<<" head";
			while(temp!=NULL){
				cout<<" -> "<<temp->data;
				temp=temp->next; 
			}
			cout<<endl;
		}
	}

private:
	int V;
	struct Adjlist* arr;

};




int main(){
	GraphN g(5);
	g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.display();
	return 0;
}