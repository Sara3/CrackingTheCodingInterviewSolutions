#include <iostream> 
#include <string> 
using namespace std; 
int main(){
string str = "this is smith";

string str1 ="20";
for(int i=0; i<str.size(); i++){
	if(str[i]==' '){
		str[i] = '%';
		str.insert(i+1,str1);	
	}
	cout<<str[i];
}
return 0;
}