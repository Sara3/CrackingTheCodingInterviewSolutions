/*
Check Permutation: 
Given 2 strings, write an method to decide if one is a permutation of the other

*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
bool ispermutation(string str1, string str2){
	bool ispermutation =false;
	if(str1.size()!=str2.size()){
		return false;
	}else{
		sort(str1.begin(), str1.end());
		sort(str2.begin(), str2.end());
		for(int i=0; i<str1.size(); i++){
			if(str1[i]!=str2[i]){
				return false;
			}
		}
		return true;
	}
}

int main(){
	string str1 = "qwer";
	string str2 = "rew"; 
	
	

	if(ispermutation(str1, str2)){
		cout<<"is permutation";
	}else
	{
		cout<<"not permutation";
	}

	return 0; 
}
