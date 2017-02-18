#include <iostream>
#include <list>
using namespace std; 
//singe Node
enum State{unvisited, visited, visiting,};
struct Node{
	int val;
	Node* next; 
    State state;
};
struct Adjlist{
	struct Node *head;
};


class graph{
	int v;
	struct Adjlist* array;


public: 
	graph(int V){
		v=V; 
		array=new Adjlist[v]; //learned it at some point, declare array that way
		for(int i=0; i<V; i++){
			array[i].head=NULL;
		}
	}

	Node* nNode(int val){
		Node* nNode = new Node();
		nNode->val=val;
		nNode->next=NULL;
		nNode->state=unvisited;
		return nNode;
	}
	//directed graph
	void addEdg(int src, int dest){
		Node *newNode = nNode(dest);
		newNode->next = array[src].head;
		array[src].head=newNode;
	}

	bool search(int s, int t){
		Node *start = nNode(s);
		Node *end   = nNode(t);
		if(start==end) return true;
		
		//operate as queue
		list<Node> q; 
		start->state=visiting;
		q.push_back(*start);
		while(!q.empty()){
			start = &q.front();
			if(start==end) return true;
			q.pop_front();
			while(start){
				if(start==end){return true;}
				start=start->next;
			}
			// for(auto i=array[start].begin(); i!=array[start].end(); i++){
			// 	i.third = state->visiting;
			// 	q.push_back(*start);
			// }
		}
		return false;
	}




	void print(){
		for(int i=0; i<v; i++){
			Node *temp= array[i].head;
			cout<<"vectex:  "<<i<<endl;
			cout<<"head";
			while(temp){
				cout<<"-> "<<temp->val;
				temp=temp->next;
			}
			cout<<endl;
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
	bool BFS(int s, int target){
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
			//cout<<s<<"  ";
			if(s==target) return true;
			q.pop_front();

			for(i=adj[s].begin(); i!=adj[s].end(); i++){
				if(!arr[*i]){
					arr[*i]=true;
					q.push_back(*i);
				}
			}
		}
		return false;
	}
};
*/
int main(){
	 graph g(4);
    g.addEdg(0, 1);
    g.addEdg(0, 2);
    g.addEdg(1, 2);
    g.addEdg(2, 0);
    g.addEdg(2, 3);
    g.addEdg(3, 3);
 	
 	if(g.search(3, 3)){
 		cout<<"yes"<<endl;
 	}else{
 		cout<<"no"<<endl;
 	}
    g.print();
 

	return 0; 
}