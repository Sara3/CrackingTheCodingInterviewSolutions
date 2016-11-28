/*
Check Permutation: 
Given 2 strings, write an method to decide if one is a permutation of the other

*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
/*
//sort = nlog n time complexity 
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
*/
//alternativly this will have O(n+m) with n extra space 
bool ispermutation(string str1, string str2){
	vector <int> m(str1.size(),0);
	if(str1.size()!=str2.size()) return false;
	for(int i=0; i<str1.size(); i++) m[str1[i]-'a']++;
	for(int i=0; i<str2.size(); i++){
		 if (m[str2[i]-'a']<=0) return false;
		 else m[str2[i]-'a']--;
	}
	for(int i=0; i<m.size(); i++){
		if(m[i]!=0) return false;
	} 
	return true; 
}

int main(){
	string str1 = "abcdeff";
	string str2 = "abcdeff"; 
	
	

	if(ispermutation(str1, str2)){
		cout<<"is permutation";
	}else
	{
		cout<<"not permutation";
	}

	return 0; 
}
