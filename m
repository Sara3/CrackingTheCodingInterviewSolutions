#include <iostream> 
#include <vector>
#include <stack>
#include <string> 
using namespace std; 


/*

bool thebarce_needed(stack<string>& mystack, string brace){
    if(mystack.empty() || mystack.top()!= brace){
        return false;
    }
    mystack.pop();
    return true; 
}
    
vector < string > braces(vector < string > values) {
stack<string> mystack; 
    int i=0; 
    while(i<values.size()){
        if(values[i] == "{" || values[i] =="(" || values[i] == "[")
            mystack.push(values[i]);
    
    if(values[i] == "}" || values[i] ==")" || values[i] == "]"){
        if(!thebarce_needed(mystack,values[i] )){
            //not matching \ how 
           // values[i]="NO";
            //values.push_back("NO");
            values.insert(values.begin()+i, "NO");
        }
        else{
            //values[i]="YES";
            values.insert(values.begin()+i, "YES");
        }
            
        }
          i++;
    }
    return values; 
}
*/

int main(){
    vector <string> values; 
    values.push_back("{");
    values.push_back("[");
    values.push_back("(");
    values.push_back(")");
    values.push_back("]");
    values.push_back("}");




    for(int i=0; values.size(); i++){
        cout<<values[i];
    }



    return 0; 
}