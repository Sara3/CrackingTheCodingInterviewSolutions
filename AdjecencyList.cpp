#include <iostream>
#include <vector>
#include <stack>
#include <queue>
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
		vector <bool>visited(V, false);
		stack <int> s; 
		Node *temp;
		s.push(0);
		visited[0] = true;
		cout<<"visited virtex : "<<0;
		while(!s.empty()){
			int k=s.top(); 
			s.pop();
			temp = arr[k].head;
			while(temp!=NULL){
				if(!visited[temp->data]){
					s.push(temp->data);
					visited[temp->data]=true;
					cout<<" -> "<<temp->data;
				}
				temp =temp->next; 
			}

		}
	}

	void BFS(){
		vector<bool> visited(V, false);
		queue <int> q;
		visited[0]=true;
		q.push(0);
		int el;
		Node *temp; 
		while(!q.empty()){
			el = q.front();
			cout<<el<<" ";
			q.pop();
			temp=arr[el].head;
			while(temp!=NULL){
				if(!visited[temp->data]){
					visited[temp->data]=true;
					q.push(temp->data);
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
	GraphN g(6);
	g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
  

   // g.display();

    g.DFS();
	return 0;
}