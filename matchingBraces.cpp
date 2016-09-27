#include <iostream> 
#include <vector>
#include <stack>
#include <string> 
using namespace std; 


/*
this program finds the if there balanced braces 
in a given string

*/

bool thebarce_needed(string opening, string closing)  // this function was not asked for and I could include it
{                                                     // in the other function but it reduces redandancy 
    if(opening == "(" && closing == ")")
        return true;
    else if(opening == "{" && closing == "}") 
        return true;
    else if(opening == "[" && closing == "]") 
        return true;
    return false;
}
    
vector < string > braces(vector <string> values) 
{
    stack<string> mystack; 
    int i=0; 
    while(i<values.size())
    {
        if(values[i] == "{" || values[i] =="(" || values[i] == "[")
        {
            mystack.push(values[i]);
        }
        else if(values[i] == "}" || values[i] ==")" || values[i] == "]")
        {
            if (thebarce_needed(mystack.top(), values[i]))
            {
                mystack.pop();
                values[i] = "YES"; //this is what was asked in the prompt if the braces matches the value becomes "YES"
            }             
            else if (!thebarce_needed(mystack.top(), values[i]) || mystack.empty())
            {
                values[i] = "NO";// this is what was asked in the prompt and the rest were taken care of
            }       
        }
        
        i++;
    }

    return values; 
}

int main()
{
    vector <string> values; 
    vector <string> result; 
    bool ismatched = true;
    values.push_back("{");
    values.push_back("[");
    values.push_back("}");
    values.push_back("]");
    values.push_back("}");


    result = braces(values);


    for(int i=0; i<result.size(); i++) //there are other ways of doing this. Was trying to follow the prompt
    {
       // cout<<result[i];
        if(result[i]=="NO") 
        {
            ismatched = false;
        } 
    }

    if(ismatched)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }


    return 0; 
}