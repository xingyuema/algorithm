#include <iostream>
#include <cstdio>

using namespace std;
int sum = 1225;
int mul = 2015;

int main(){
	for(int i = 1;i <= 46;i++){
		int t1 = i*(i+1);
		for(int j = i+2;j <= 48;j++){
			int t2 = j*(j+1);
			int s = t1+t2+(sum-2*(i+j+1));
			if(s == mul){
				cout << "i == " << i << "\t" << i+1 << "\tj == " << j << "\t" << j+1 << endl;	
			}
		}
	}
	return 0;
}


