#include <iostream>
using namespace std; 
bool pal(){
	string str = "2*4-2"; 
	int beg = 0; 
	int end = str.size()-1; 
	while(beg<=end){
		if(str[beg]!=str[end]){
			return false;
		}
	}
	return true; 
}

int main(){
	if(pal()==true){
		cout<<"yes";
	}
	
	return 0; 
}