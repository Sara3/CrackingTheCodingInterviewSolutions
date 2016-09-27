#include <iostream>
#include <string>
using namespace std;

/*one edit away. delete, add, replace */
bool replace(string first,string second){
	bool foundDiff = false; 
	for(int i=0; i<first.size(); i++){
		if(first[i]!=second[i]){
			if(foundDiff){
				return false;
			}else
			{
				foundDiff =true;
			}

		}
	}
	return true;
}
bool deleteaddfunction(string first, string second)
{
	int index1 = 0;
	int index2 = 0;

	while(index1<first.size() && index2<second.size())
	{
		if(first[index1]!=second[index2])
		{
			if(index2!=index1)
			{
				return false;
			}
			index2++;
		}
		else
		{
			index1++;
			index2++; 
		}
	}
	return true;
}

bool oneEditAway(string first, string second){
	if(first.size()==second.size()){
		return replace(first, second);
	}
	else if(first.size()+1==second.size()){
		return deleteaddfunction(first, second);
	}
	else if(first.size()==second.size()+1){
		return deleteaddfunction(first, second);
	}
	return false; 
}

int main(){
	string str1;
	string str2;
	cin>>str1;
	cin>>str2;

	if(oneEditAway(str1, str2)){
		cout<<"yes!";
	}else{
		cout<<"not one edit away";
	}

	return 0; 
}