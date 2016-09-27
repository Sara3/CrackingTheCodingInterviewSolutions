#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <limits>
#include <algorithm>
using namespace std; 
/*
You are given N sticks, where the length of each stick is a positive integer. 
A cut operation is performed on the sticks such that all of them are reduced
by the length of the smallest stick

e.g.
input: 
6
5
4
4
2
2
8
output: 
6
4
2
1

*/

vector<int> cutSticks(vector<int> _lengths){
	  int min = *min_element (_lengths.begin(), _lengths.end());
    while(_lengths.size() >=1)
    {
        cout<<_lengths.size()<<endl;
        for(int i=0; i<_lengths.size(); i++)
        {
            if(_lengths[i]>=1)
            {
               _lengths[i] = _lengths[i]-min;
            }
        }
        _lengths.erase(remove(_lengths.begin(), _lengths.end(),0), _lengths.end());
        min = *min_element (_lengths.begin(), _lengths.end());
    }
return _lengths;
}

int main()
{
	ifstream myfile;
	myfile.open("cutStickInput.in");//inout the vector from a file
	vector<int> res;

	int _lengths_size = 0; 
	myfile >> _lengths_size;
	myfile.ignore(numeric_limits<streamsize>::max(), '\n');
	vector<int> _lengths;
	int _lengths_item;
	for(int _lengths_i =0; _lengths_i <_lengths_size; _lengths_i++)
	{
		myfile >>_lengths_item;
		myfile.ignore(numeric_limits<streamsize>::max(),'\n');
		_lengths.push_back(_lengths_item);
	}
	
	res = cutSticks(_lengths);
	for(int res_i=0; res_i <res.size(); res_i++)//not necessery because it has 0 element
	{
		cout<<res[res_i];
	}
	myfile.close();
	return 0;

}