/* Hash table practice */

#include <iostream> 
#include <map>
#include <vector> 
#include <unordered_map>
using namespace std;

int main(){
	map <int, int> mymap; 
	map <int, int>:: iterator it;
	int mynum [7] = {11,2,12,2,2,2,2};

	int i=0;
	for(i=0; i<7; i++){
		mymap[mynum[i]]=1;
	}

	for(it = mymap.begin();it!=mymap.end(); it++ ){
		cout<<it->first <<",";
	}

	return 0; 
}