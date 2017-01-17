#include <iostream>
#include <string>
#include <string.h>
using namespace std; 


class StringUtils {
public:
	static string reverse(string s){
		string str; 
		for(int i=s.size(); i>=0; i--){
			str = str+s[i];
		}	
		return str; 
	}

	static string Subreverse(string s, int startIndex, int endIndex){
		string substr, subStr1, subStr2;
		
		if(startIndex <0){
			startIndex = 0;
		}
		if(endIndex<0){
			endIndex =s.size()-1;
		}

		if(startIndex!=0){
			substr = s.substr(0, startIndex);
		}
		subStr1 = reverse(s.substr(startIndex, endIndex+1));
		if(endIndex!=s.size()-1){
			subStr2 = s.substr(endIndex, s.size()-1);	
		}
		return substr+subStr1+subStr2; 
	}

	string reAllWords(string s){
		int start =0; 
		string str; 
		int count =0;
		for(int i=0; i<s.size(); i++){
			count++;
			if(s[i]==' ' ){
				str = str+reverse(s.substr(start, count-1))+' ';
				start = i+1;
				count =0; 
			}
			if(i==s.size()-1){
				str = str+reverse(s.substr(start));
			}
		}
		return str;
	}
	bool isPal(string s){
		int start =0;
		int end = s.size()-1;
		while(start<=end){
			if(s[start]==s[end]){
				start++;
				end--;
			}else{
				return false;
			}
		}
		return true;
	}
	void findSub(string str2, string str1){
		int i, j;
		for(i=0, j=0; j<str2.size() && i<str1.size(); i++)
			(str1[i]==str2[j]) ? j++: j=0;
		(j==str2.size())? cout<<"found at position "<<i-j+1: cout<<"not found";
	}
};

int main(){
	StringUtils b; 
	string a = "abcpba"; 
	string c;
	
	//c =b.Subreverse(a, 0,3);
	//cout<<c;

	//b.reAllWords(a);
	b.findSub("ba", a);

	return 0; 
}