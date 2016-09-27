/*
Non dominatable entities 
Given are pairs of integers. Pair i is "dominated" 
by pair j if ai < aj and bi < bj. 
out put how many pairs there are that are not dominated by any other pair?

approach: count all pair that are "dominated" and subtract that from the size of the whole array
ex:
input: 
5
3 2
8 7
6 9
3 4
7 8

output:
3

*/

#include <iostream>
#include <vector>
#include <fstream>
using namespace std; 

int main(){

	vector<vector<int> > v;
	ifstream myfile;
	myfile.open("num.in");//need an input file with n number of pairs 
	int n;
	myfile>>n;
	int input;
	int count = 0;
	
	
	for(int i=0; i<n; i++)
	{
		vector<int> temp; 
		for(int j=0; j<2; j++)
		{	
			myfile>>input;
			temp.push_back(input);
		}
		v.push_back(temp);
	}

	myfile.close();
	

	for(int i=0; i<v.size()-1; i++)
	{
		for(int j=0; j<v[i].size()-1; j++)
		{
			if(v[i][j]<v[i+1][j] && v[i][j+1]<v[i+1][j+1])
			{
				//cout<<v[i][j]<<" "<<v[i][j+1]<<" "<<endl;
				count++;
			}
				
		}
		//cout<<endl;	
	}
		
	cout<<v.size()-count;


	return 0;
}