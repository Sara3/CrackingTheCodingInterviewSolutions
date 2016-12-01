#include <iostream>
#include <algorithm>
using namespace std; 
#define N 5

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
}
void rotateMatrixClockwise(int mat[][N])
{
	for (int x = 0; x < N / 2; x++)
	{
		for (int y = x; y < N-x-1; y++)
		{
			int temp = mat[x][y];
			mat[x][y] = mat[N-1-y][x];
			mat[N-1-y][x] = mat[N-1-x][N-1-y];
			mat[N-1-x][N-1-y] = mat[y][N-1-x];
			mat[y][N-1-x] = temp; 
			
		}
	}
}
void display (int mat[][N]){
	for(int i=0; i<N; i++){		
		for(int j=0; j<N; j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;
}

int main(){
int mat[N][N] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};

display(mat);
rotateMatrix(mat);
display(mat);
rotateMatrixClockwise(mat);
display(mat);


	return 0;
}