#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main(){
	for(int d = 2;d < 9;d++){
		for(int b = 2;b < 9;b++){
			if(b == d) continue;
			for(int g = 2;g < 9;g++){
				if(b == g || d == g)	continue;
				int c = b+1;
				if(c+g <= 10)	continue;
				if(c == d || c == b || c == g)	continue;
				int sum = 9000+b*100+c*10+d+1000+g*10+b;
				for(int x = 2;x < 9;x++){
					if(x == b || x == d || x == g || x == c)	continue;
					if(sum == 10000+c*100+b*10+x){
						printf("%2d%d%d%d\n",9,b,c,d);
						printf("+%d%d%d%d\n",1,0,g,b);
						printf("%d%d%d%d%d\n",1,0,c,b,x);
					} 
				}
			}
		}
	}
	
	return 0;
}



/* 
int main(){
	string s = "";
	int a=9,e=1,f=0,d,b,x,c,g;
	
	for(c = 2;c < 9;c++){
		for(g = 2;g < 9;g++){
			if(c != g){
				if(c+g > 9){
					//≤‚ ‘ 
					//cout << c << "c∫Õg" << g <<endl;
					for(b = 2;b < 9;b++){
						if(b != c && b != g){
							if((c+g-10) == b){
								if(b+1 == c){
									//≤‚ ‘
									cout << "c: " << c << " g: " << g << " b: " << b <<endl;  
									for(int d = 2;d < 9;d++){
										if(d != b && d != c && d != g){
											x = d + b;
											printf("%d\n",x);
											printf("\t%d %d %d %d\n",a,b,c,d);
											printf("+       %d %d %d %d\n",e,f,g,b);
											printf("      %d %d %d %d %d\n",e,f,c,b,x);
											return 0;
											
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
*/ 


