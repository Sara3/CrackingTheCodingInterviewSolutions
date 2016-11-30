#include <iostream>
#include <algorithm>
using namespace std; 
#define N 5


void rotateMatrix(int mat[][N]){
	//squares?
	for(int x=0; x<N/2; x++){
		//current group
		for(int y=x; y<N-x-1; y++){
			int temp = mat[x][y];
			cout<<" temp = "<<temp<<endl;
			mat[x][y]=mat[y][N-1-x];
			cout<<" mat[x][y] = "<<mat[x][y];
			mat[y][N-1-x] = mat[N-1-x][N-1-y];
			cout<<" mat[y][N-1-x] = "<<mat[y][N-1-x];
			mat[N-1-x][N-1-y]=mat[N-1-y][x];
			cout<<" mat[N-1-x][N-1-y] = "<<mat[N-1-x][N-1-y];
			mat[N-1-y][x]=temp;
			cout<<" mat[N-1-y][x] = "<<mat[N-1-y][x];
		}
		cout<<endl<<endl;
	}
}/*
void rotateMatrix(int mat[][N])
{
	// Consider all squares one by one
	for (int x = 0; x < N / 2; x++)
	{
		// Consider elements in group of 4 in 
		// current square
		for (int y = x; y < N-x-1; y++)
		{
			// store current cell in temp variable
			int temp = mat[x][y];

			// move values from right to top
			mat[x][y] = mat[y][N-1-x];

			// move values from bottom to right
			mat[y][N-1-x] = mat[N-1-x][N-1-y];

			// move values from left to bottom
			mat[N-1-x][N-1-y] = mat[N-1-y][x];

			// assign temp to left
			mat[N-1-y][x] = temp;
		}
	}
}*/
int main(){
	int mat[N][N] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
/*	
int temp, temp2;
int t_1, t_2, b_1, b_2; 
int j = n-1;
int i=0; 
int l =0;
int h = n-1;
while(i<4){
	temp = a[i][h]; //top2
	a[i][h]= a[l][i];//top
	temp2=a[h][j];//bot
	a[h][j]=temp;//will have tom cor
	a[l][i] = a[j][l]; // bottom corner will go to top corner
	a[j][l] = temp2; //bot will go bot2

	cout<<"Top = "<<a[l][i]<<" ";
	cout<<"top2= "<<a[i][h]<<" ";
	cout<<"bot2 = "<<a[j][h]<<" ";
	cout<<"bot= "<<a[j][l]<<" ";	
	cout<<endl;
	
	j--;
	i++;

}
*/
 rotateMatrix(mat);

for(int i=0; i<N; i++){		
	for(int j=0; j<N; j++){
		cout<<mat[i][j]<<" ";
	}
	cout<<endl;
}
	return 0;
}