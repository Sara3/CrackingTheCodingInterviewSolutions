#include <iostream>
using namespace std; 

class stack {
public:
	stack(){
		
		stackSize = 6;
		numOfStacks = 3;
		data = new int[stackSize*numOfStacks];
		size = new int[numOfStacks];
		for(int i=0; i<stackSize*numOfStacks; i++){
			data[i]=0;
		}
		for(int i=0; i<numOfStacks; i++){
			size[i]=0;
		}
	}

	stack(int stackSize, int numOfStacks){
		
		data = new int[stackSize*numOfStacks];
		size = new int[numOfStacks];
		for(int i=0; i<stackSize*numOfStacks; i++){
			data[i]=0;
		}
		for(int i=0; i<numOfStacks; i++){
			size[i]=0;
		}
	}

	int indexOfStack(int numStack){
		int index = (stackSize*numStack-stackSize)+size[numStack-1];
		return index;
	}

	void push(int numStack, int val){
		if(isFull(numStack)){
			//throw invalid_argument( "That stack is full" );
		}
		
		data[indexOfStack(numStack)] = val;
		size[numStack-1]++;
	}
	
	int pop(int numStack){
		if(isEmpty(numStack)){
			//throw invalid_argument( "No value to pop" );
		}
		int n = data[indexOfStack(numStack)-1];
		data[indexOfStack(numStack)-1] =0;
		size[numStack-1]--;
		return n;
	}


	int peek(int numStack){
		if(isEmpty(numStack)){
			//throw invalid_argument( "No value to peek" );
		}
		return data[indexOfStack(numStack)-1];
	}
	
	bool isEmpty(int numStack){
		return size[numStack-1]==0;
	}

	bool isFull(int numStack){
		return size[numStack-1]==stackSize; 
	}


private: 
	int stackSize;
	int numOfStacks; 
	int *data;
	int *size; 
};

int main(){
	stack a;
	a.push(1, 6);
	a.push(3, 2);
	a.push(3, 1);



	return 0; 
}