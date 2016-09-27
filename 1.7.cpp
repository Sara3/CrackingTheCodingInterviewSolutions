#include <iostream>
using namespace std; 
/*rotate matrix */
void rotate(int [][] matrix, int n){
	for(int layer =0; layer <n/2; ++layer){
		int first = layer; 
		int last = n-1-layer; 
		for(int i=0; i<last; ++i){
			int offset = i-first;
			int top = matrix[first][i];
			matrix[first][i] = matrix[last-offset][first];
			matrix[last][last-offset] = matrix[i][last];
			matrix[i][last]=top; 
		}
	}
}

int main(){
	



	return 0; 
}