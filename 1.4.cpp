#include <iostream>
#include <algorithm>
using namespace std; 

int main(){
 string str = " tactcoa";
 int count = 0;
 bool match=false;

 sort(str.begin(), str.end());
 for(int i=0; i<str.size(); i++){
 	cout<<str[i];
 }
cout<<endl;
 for(int i=0; i<str.size(); i=i+2){

 	//cout<<"i = "<<i<<str[i]<<endl;
 	if(str[i]==str[i+1])
 	{
 		match = true;
 		
 	}else{
 		i--;
 		count++;
 	}
 }
if(count ==1 &&match == true){
	cout<<"palindrome permutation";
}else {
	cout<<"not palindrome permutation";
}
//cout<<count;
	return 0;
}
