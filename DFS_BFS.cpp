#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <vector> 
using namespace std; 


class Graph{
	int V;
	list<int> *adj;

public:
	Graph(int V){
		this->V=V;
		adj = new list<int>[V];
	}
	void addEdge(int v, int w){
		adj[v].push_back(w);
	}
	void DFS(int s){
		vector<bool> visited(V, false);
		stack <int> stack;
		stack.push(s);
		while(!stack.empty()){
			s=stack.top();
			stack.pop();
			if(!visited[s]){
				cout<<s<<" ";
				visited[s] = true;
			}
			for( auto i= adj[s].begin(); i!=adj[s].end(); ++i){
				if(!visited[*i]){
					stack.push(*i);
				}
			}

		}

	}


	void BFS(int s){
		vector<bool> visited(V, false);
		queue<int> q;
		visited[s]=true;
		q.push(s);

		while(!q.empty()){
			s=q.front();
			cout<<s<<" ";
			q.pop();

			for(auto i = adj[s].begin(); i!=adj[s].end(); i++ ){
				if(!visited[*i]){
					visited[*i]=true;
					q.push(*i);
				}
			}
		}
	}

};

/*

class Graph{
	int v; 
	list<int> *adj;

public:
	Graph(int V){
		v=V; 
		adj= new list<int>[V]; 
	}
	void addEdg(int src, int dest){
		adj[src].push_back(dest);
	}
	void BFS(int s){
		list<int> q; 
		bool arr[v];
		for(int i=0; i<v; i++){
			arr[i]=false; 
		}
		q.push_back(s);
		arr[s]=true;
		list<int>::iterator i;
		while(!q.empty()){
			s=q.front();
			cout<<s<<"  ";
			q.pop_front();

			for(i=adj[s].begin(); i!=adj[s].end(); i++){
				if(!arr[*i]){
					arr[*i]=true;
					q.push_back(*i);
				}
			}
		}
	}
};

*/
int main(){
	   Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;


}
