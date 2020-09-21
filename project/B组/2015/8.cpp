#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	int w,m,n;
	cin >> w >> m >> n;
	int rm = m % w == 0 ? m/w : (m/w)+1;
	int rn = n % w == 0 ? n/w : (n/w)+1;
	
	int cm = 0;
	int cn = 0;
	
	if(rm % 2 == 0)	cm = rm*w-m+1;
	else cm = w-(w*rm-m);
	
	if(rn % 2 == 0)	cn = rn*w-n+1;
	else cn = w-(w*rn-n);
	
	cout << abs(rm-rn) + abs(cm-cn) << endl;
	
	return 0;
}



