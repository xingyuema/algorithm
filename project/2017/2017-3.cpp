#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(){
	ll data[30][30];
	ll t;
	ll N = 1;
	for(int i = 0;i < 30;i++){
		N <<= 1;
	}
	cout << N << endl;
	for(int i = 0;i < 29;i++){
		for(int j = 0;j <= i;j++){
			cin >> t;
			data[i][j] = t*N;
		}
	}
	for(int i = 0;i < 29;i++){
		for(int j = 0;j <= i;j++){
			ll half = data[i][j] / 2;
			data[i+1][j] += half;
			data[i+1][j+1] += half;	
		}
	}
	
	sort(data[29],data[29]+30);
	
	cout << data[29][0]/2086458231 << endl;

	/*
	for(int i = 0;i < 29;i++){
		for(int j = 0;j <= i;j++){
			cout << data[i][j] << " ";
		}
		cout << endl;
	}
	*/
	
	
	return 0;
}



