#include <iostream>

using namespace std;

int ans = 0;

void f(int k,int cnt){
	if(k > 13 || cnt > 13) return;
	if(k == 13 && cnt == 13){
		++ans;
		return;
	}
	for(int i = 0;i < 5;i++){
		f(k+1,cnt+i);
	}
}

int main(){
	//分配的是第几张牌、有几张牌了 
	f(0,0);
	cout << ans << endl;
	return 0;
}


