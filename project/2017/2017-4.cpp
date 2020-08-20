#include <iostream>

using namespace std;

int v[7][7];
int ans = 0;
int x[4] = {1,0,-1,0};
int y[4] = {0,1,0,-1};
void solve(int i,int j){
	if(i == 0 || i == 6 || j == 0 || j == 6){
		ans++;
		return;
	}
	v[i][j] = 1;
	v[6-i][6-j] = 1;
	for(int k = 0;k < 4;k++){
		int nx = i+x[k];
		int ny = j+y[k];
		if(nx < 0 || nx > 6 || ny < 0 || ny > 6) continue;
		if(!v[nx][ny])
			solve(nx,ny);
	}
	v[i][j] = 0;
	v[6-i][6-j] = 0;
}


int main(){
	solve(3,3);
	cout << ans / 4 << endl;
	return 0;
}





