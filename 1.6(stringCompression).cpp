/*
A method that prepform basic string compression using the counts of repeated string


*/
#include <iostream>
#include <map>
#include <iterator>
#include <vector> 
using namespace std; 
/*string comprission*/

int main(){

vector <int> v ('z'-'a');
string str = "abcabcb";

char s;
for(int i=0; i<str.size(); i++){
	int val = str[i]-'a';
	v[val]++;
	
}
char m;
for(int i=0; i<v.size(); i++){
	if(v[i]!=0){
			m = i+'a';
			cout<<m<<v[i];
		}
}
	return 0; 
}


	/*
	map<char, int>phrase1;
	map<char, int>::iterator it; 
	string phrase;
	cin>>phrase; 
	
	for(int i=0; i<phrase.size(); i++){


		phrase1[phrase[i]] = nd++;
	}






	it=phrase1.begin();
	while( it!=phrase1.end()){
		cout<<"char = "<<it->first<<" number = "<<it->second<<endl;
	
		 it++;
	}


*/

