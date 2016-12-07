#include <iostream>
#include <math.h> 
#include <forward_list>
using namespace std; 

int main(){
	forward_list<int> a; 
	forward_list<int> b; 
	forward_list<int> c; 
	a.assign({7,1,6});
	b.assign({5,9,2});

	int sum =0;
	int sum2 =0;
	int total =0;
	int j=0;

	for(int&i:a) {
		sum += i*pow(10,j);
		j++;
	}
	
	j=0;
	for(int&i:b) {
		sum2 += i*pow(10,j);
		j++;
	}
	total=sum2+sum;

	while (total != 0) {
		c.push_front(total%10);
	    total /= 10;
	}

	for(int&i:c) {
		cout<<i<<" ";
	}

	return 0; 
}