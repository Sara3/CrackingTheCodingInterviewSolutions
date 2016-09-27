/*

* Given an array of Roman titles sort it as follows: sort it on the name unless the names are equal, 
* in which case you have to sort it on the ordinal of the numerals.
* Examples:
* Henry II, Edward VIII => Eward VII, Henry II
* Richard V, Richard II, Richard X => Richard II, Richard V, Richard X

*/


#include <iostream>
#include <string>
#include <vector>
#include <fstream> 
#include <algorithm>
#include <iterator>
using namespace std; 

vector <string> splitString(const string &s)
{
	vector<string> v;
	int index_space; 
	string s_a; 
	string s_b; 

	for(int i=0; i<s.size(); i++)
	{
		if(s[i]==' ')
		{
			index_space = i; 
		}
	}
	s_a.assign(s.begin(), s.begin()+index_space);
	s_b.assign(s.begin()+(index_space+1), s.end());
	v.push_back(s_a);
	v.push_back(s_b);
	return v;
}

int romanToDig(string s){
	int result =0; 
	for(int i=0; i<s.size(); i++){
		if(s[i]=='L') 
		{
			result+=50;
		}
		else if(s[i]=='X')
		{
			if(i<s.size()-1 && (s[i+1]=='L'))
			{
				result-=10;
			}
			else
			{
				result+=10;
			}	
		}
		else if(s[i]=='V')
		{
			result+=5;
		}
		else if(s[i]=='I')
		{
			if(i<s.size()-1 && (s[i+1]=='X' || s[i+1]=='V'))
			{
				result--;
			}
			else
			{
				result++;

			}
		}
	}
	return result; 
}

bool compare (string a, string b)
{
	vector<string> s1 = splitString(a);
    vector<string> s2 = splitString(b);
    if(s1[0]<s2[0])
    {
    	return true;
    }
    if(s1[0]==s2[0] && romanToDig(s1[1])<=romanToDig(s2[1]))
    {
    	return true;
    }
    return false;
}	


int main(){

	vector <string> names;
	vector <string> :: iterator it; 
	names.push_back("Henry XXI");
	names.push_back("Lous V");
	names.push_back("Henry V");
	names.push_back("Silva I");
	names.push_back("James II");
	names.push_back("Henry XI");

	sort(names.begin(), names.end(), compare);

	it = names.begin();

	while(it!=names.end())
	{
		cout<<*it<<endl;
		it++;
	}

	return 0;
}