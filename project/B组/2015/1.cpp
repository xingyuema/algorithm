#include <iostream>
#include <sstream>
using namespace std;

void i2s(int i,string &s){
	stringstream ss;
	ss << i;
	ss >> s;
}

int main(){
	int ans = 0;
	string s;
	for(int i = 10000;i <= 99999;i++){
		i2s(i,s);
		if(s.find('4') == string::npos) ans++;
	}
	cout << ans << endl;
	return 0;
}


/*·¨Ò» 
bool is_right(int i){
	int n = 5;
	while(n > 0){
		if(i % 10 == 4)
			return false;
		i /= 10;
		--n;
	}
	return true;
}

int main(){
	int ans = 0;
	for(int i = 10000;i < 100000;i++){
		if(is_right(i)){
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}
*/ 


