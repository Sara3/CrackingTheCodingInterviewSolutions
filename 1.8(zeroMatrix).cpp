#include <iostream>
#include <string.h>
using namespace std; 
#define N 5
int main(){
		bool hasZero =0;
		int mat[N][N] = {{1,2,3,4,5},{6,7,0,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
		int* cur= &(mat[0][0]);
		for(int i=0; i<N*N; i++){
				if(*cur==0){
					hasZero = true; 
					break;
				}
			
			cur++;
		}

		if(hasZero){
			memset(mat,0, sizeof(mat[0][0])*N*N );
		}

for(int i=0; i<N; i++){
	for(int j=0; j<N; j++){
		cout<<mat[i][j]<<endl;
	}
	return 0; 
}
}