#include <iostream>
#include <list>
using namespace std; 

class Graph{
	int v;
	list<int> *adj; 
public:
	Graph(int v){
		this->v=v;
		adj = new list<int>[v];//?
	}

	void addEdge(int V, int w){
		adj[V].push_back(w);
	}


};

int main(){
	Graph g(5);
	g.addEdge(1, 0);

}