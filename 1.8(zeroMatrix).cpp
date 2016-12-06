#include <iostream>
#include <vector>
#include <string.h>
using namespace std; 

#define N 3
/*
vector<vector<int> > setzero(int a[N][N], int m, int j){
	vector<vector<int> >arr(N, vector<int>(N));
	for(int i=0; i<N; i++){
		arr[i].assign(a[i], a[i]+N);
	}
	fill(arr[m].begin(), arr[m].end(), 0);
	for(int l=0; l<N; l++){
		arr[l][j] = 0;
	}

	return arr; 
}
*/

void zeroRow(int a[N][N],int row){
	for(int i=0; i<N; i++){
		a[row][i]=0;
	}
}
void zeroCol(int a[N][N],int col){
	for(int i=0; i<N; i++){
		a[i][col] =0; 
	}
}

void setzero(int a[N][N]){

	bool row[N] ;
	bool col[N] ;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(a[i][j]==0) {
				row[i] = true;
				col[j] = true;
			}
		}
	}
	for(int l=0; l<N; l++){
		if(row[l]) {
			cout<<row[l]<<endl;
			zeroRow(a, l);}
		if(col[l]) zeroCol(a, l);
	}
}

void display(int a[N][N]){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
int a[N][N]= {{1,2,3},{6,7,0},{8,9,3}};

setzero(a);
display(a);

	return 0; 
}
