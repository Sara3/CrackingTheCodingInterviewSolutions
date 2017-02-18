#include <iostream>
using namespace std; 


int main (){
for(int i=0; i<=100; i++){
	if(i%5==0 && i%3==0){
		cout<<"AlPha Beta"<<endl;
	}else if(i%3==0){
		cout<<"Alpha"<<endl;
	}else if(i%5==0){
		cout<<"Beta"<<endl;
	}else{
		cout<<i<<endl;
	}
}
return 0;
}