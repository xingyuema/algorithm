#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

typedef long long ll;

void i2s(ll i,string &s){
	stringstream ss;
	ss << i;
	ss >> s;
} 

bool check(string s_i,string s_ans){
	for(int i = 0;i < s_i.length();i++){
		if(s_ans.find(s_i[i]) != string::npos){
			return false;
		}
	}
	return true;
}


int main(){
	string s_i,s_ans;
	ll x = 0,ans = 0;
	for(ll i = 1;i < 10;i++){
		for(ll j = 0;j < 10;j++){
			if(j != i){
				for(ll k = 0;k < 10;k++){
					if(k != i && k != j){
						for(ll m = 0;m < 10;m++){
							if(m != i && m != j && m != k){
								for(ll n = 0;n < 10;n++){
									if(n != i && n != j && n != k && n != m){
										for(ll l = 0;l < 10;l++){
											if(l != i && l != j && l != k && l != m && l != n){
												x = i*100000+j*10000+k*1000+m*100+n*10+l;
												ans = pow(x,2);
												i2s(x,s_i);
												i2s(ans,s_ans);
												if(check(s_i,s_ans)){
													cout << "i = " << s_i << "ans = " << s_ans << endl;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	return 0;
}























