#include <iostream>
#include <string> 
using namespace std; 

bool isRotation(string str1, string str2){
	string str3= str2+str2; 
	if(str1.size()!=str2.size()) return false;
	string::size_type pos = str3.find(str1);
	if (pos == string::npos) return false;
	return true; 
}


int main(){
	string str1 = "waterbottle";
	string str2 = "erbottlewat";
	if(isRotation(str1, str2)) cout<<"works ";

	return 0;
}