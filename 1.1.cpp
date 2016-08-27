//is Unique: Implement an algorithm to determine if a //string has all unique characters. No additional 
//data tractures 

#include <iostream>
using namespace std;
string isunique(string str){
	for(int i=0; i<str.size(); i++){
		for(int j= 1; j<str.size(); j++){
			if(str[i]==str[j]){
				return "not unique";
			}
			else{
				return "unique";
			}
		}
	}
}

int main(){
string str; 
str="mb";

str = isunique(str);
cout<<str;

return 0;
}


// int main(){
//     string str;
// 	str="aabb";
    
//     int i=0;
//     while(i<str.size()-1){
//         if(i>-1&& i<str[i]==str[i+1]){
//             str.erase(i,2);
//             i--;
//         }
//         else{
//             i++;
//         }
//     }
    
//    if(str.empty()){
//        cout<<"empty";
//    }else
//        {
//        cout<<str<<endl;
//    }

//    return 0;
// }
