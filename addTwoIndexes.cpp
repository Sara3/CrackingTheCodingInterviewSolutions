#include <iostream>
#include <map>
#include <vector>
#include <array>
using namespace std; 
 void Targer(int arr[]){
	map<int, int> map;
	int index[2];
	int target = 9; 
	
	for(int i=0; i<6; i++){
		map.insert(pair<int, int>(arr[i], i));
	}
	for(int i=0; i<6; i++){
		auto it = map.find(target-arr[i]);
		if(it!=map.end()){
			index[0]=i;
			index[1]=it->second;
		}
	}

	cout<<"index 1 = "<<index[0];
	cout<<"index 2 = "<<index[1];
}

int main(){
	
	int arr[]={1,2,3,4,5,6};
	int a[2];
	Targer(arr);
	



	

	
	return 0;
}