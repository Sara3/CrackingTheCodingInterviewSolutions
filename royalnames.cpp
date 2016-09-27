/*
#include<bits/stdc++.h>
using namespace std;
int romanToInt(string s){
	int res=0;
	for(int i=0;i<s.length();++i){
		if(s[i]=='L')
			res+=50;
		else if(s[i]=='X'){
			if(i<s.length()-1 && (s[i+1]=='L') )
				res-=10;
			else
				res+=10;
		}
		else if(s[i]=='V')
				res+=5;
		else if(s[i]=='I'){
			if(i<s.length()-1 && (s[i+1]=='X' || s[i+1]=='V') )
				res--;
			else
				res++;
		}
	}
	return res;
}
bool comp(string a,string b){
	istringstream isA(a);
	istringstream isB(b);
	string splitStringA[2],splitStringB[2];
	string temp;
	int i=0;
	while(isA>>temp)
		splitStringA[i++]=temp;
	i=0;
	while(isB>>temp)
		splitStringB[i++]=temp;
	if(splitStringA[0]<splitStringB[0])
		return true;
	else if(splitStringA[0]>splitStringB[0])
		return false;
	else
		return romanToInt(splitStringA[1])<=romanToInt(splitStringB[1]);
}
int main(){
	string names[6]={"Richard V","Henry VI","Edward II","Richard XXV","Henry IX","Edward LII"};
	sort(names,names+6,comp);
	for(int i=0;i<6;++i)
		cout<<names[i]<<endl;
return 0;
}
*/

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

map<char, int> vals = { {'I', 1}, 
                        {'V', 5}, 
                        {'X', 10}, 
                        {'L', 50}, 
                        {'C', 100}, 
                        {'D', 500}, 
                        {'M', 1000}
                    };


vector<string> split(const string &s, char delim) {
    stringstream ss(s);
    string item;
    vector<string> tokens;
    while (getline(ss, item, delim)) {
        tokens.push_back(item);
    }
    return tokens;
}


int romanToInt(string s){
    int res = vals[s[s.size() - 1]];
    for (int i = s.size() - 2; i >= 0; i--) {
        if (vals[s[i]] < vals[s[i+1]])
            res -= vals[s[i]];
        else
            res += vals[s[i]];
    }
    return res;
}

bool comp(string a, string b) {
    vector<string> s1 = split(a, ' ');
    vector<string> s2 = split(b, ' ');
    for (auto s: s1)
        cout << s << endl;
    if (s1[0] < s2[0]) return true;
    if (s1[0] == s2[0] and romanToInt(s1[1]) <= romanToInt(s2[1]))
        return true;
    return false;   

}

int main(){
    vector<string> names = {"Richard V","Henry VI","Edward II","Richard XXV","Henry IX","Edward LII"};
    sort(names.begin(), names.end(), comp);
    for (auto name: names)
        cout<< name << '\t';
return 0;
}