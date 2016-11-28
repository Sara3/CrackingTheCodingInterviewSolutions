//is Unique: Implement an algorithm to determine if a //string has all unique characters. No additional 
//data tractures 

#include <iostream>
using namespace std;

//bruth force
bool isunique(string str){
	int checker=0;
	for(int i=0; i<str.size(); i++){
		int val=str[i]-'a'; //rebase it
		if((checker&(1<<val))>0){ // it means that the data exceed he 32 bit of 0 which was used as array
			return false;
		}
		checker=checker|(1<<val); //add one to each unique num 
	}
	return true;
}
int main(){
string str; 
str="abcde";

if(isunique(str))
	cout<<"yes";

return 0;
}


