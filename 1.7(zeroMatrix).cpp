#include <iostream>
using namespace std;
#define N 5
 void zerorow(int a[N][N], int j){
 	for(int i=0; i<N; i++){
 		a[i][j] = 0;
 	}
 }
 void zerocol(int a[N][N], int i){
 	for(int j=0; j<N; j++){
 		a[i][j] = 0;
 	}
 }
void zeromatrix (int a[N][N]){
	bool row[N] = {0};
	bool col[N] = {0};
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(a[i][j]==0){
				row[i] = true;
				col[j] = true;
			}
		}
	}
	for(int l=0; l<N; l++){
		if(row[l]){
			zerorow(a, l);
		}
	}
	for(int l=0; l<N; l++){
		if(col[l]){
			zerocol(a , l);
		}
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
	int a[N][N] = {{1,2,3,4,5},{1,2,3,4,5}, {1,2,0,4,5}, {1,2,3,4,5}, {1,2,3,4,0}};
	display(a);
	zeromatrix(a);
	cout<<endl;
	display(a);
	return 0;
}
