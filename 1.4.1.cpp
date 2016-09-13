#include <iostream> 
#include <string> 
#include <map>
#include <vector>
using namespace std; 
/* Map each char to a num a-0, b-1 */
int getCharNumber(char c){
	int val = c; 
	if(val>='a' && val<='z'){
		return val-'a'; 
	}else if(val>='A' && val<='Z'){
		return val-'A';
	}
	return -1;
}

/*count how many times each character appears */
vector<int> buildcharfrequencytable(string phrase){
	vector<int> table('z'-'a');
    for(int i=0; i<phrase.size(); i++)
    {
    	int x = getCharNumber(phrase[i]);
    	table[x]++;
    }
	return table; 
}

/*check that no more than one char has odd count */

bool checkMaxOdd (vector <int>table){
	bool foundOdd = false; 
	for(int i=0; i<table.size(); i++){
		if(table[i]%2==1){
			if(foundOdd){
				return false;
			}
			foundOdd = true; 
		}
	}
	return true; 
}
bool ispermutationofpalindrom(string phrase){
	vector <int> table = buildcharfrequencytable(phrase);
	return checkMaxOdd(table);
}

int main()
{
	string s;
	cin>>s;
	
vector<int>m;
	// m=buildcharfrequencytable(s);
	// cout<<m.size();

	 for(int i=0; i<m.size(); i++){
	 	//cout<<i<<" = "<<m[i]<<endl;
	 }

	 bool m1;
	 m1 =  ispermutationofpalindrom(s);
	 if(m1){
	 	cout<<"yess!";
	 }
	return 0; 
}