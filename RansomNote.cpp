#include <iostream> 
#include <string> 
#include <map>
#include <vector>
using namespace std; 
// rnsomeNote is a subset of mag
int main(){
	
	string rnsomNote = "aa";
	string mag = "aab";
	vector <int> v (26,0);
	for(int i=0; i<mag.size(); i++){
		v[mag[i]-'a']++;
	}
	for(int i=0; i<rnsomNote.size(); i++){
		v[mag[i] - 'a']++;
		if(v[rnsomNote[i]-'a']<=0){
			return false;
		}else{
			v[rnsomNote[i]-'a']--;
		}
	}
	
	
	return true;


}