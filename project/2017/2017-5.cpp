#include <iostream>
#include <cstdio>
using namespace std;

/*
标题：取数位

求1个整数的第k位数字有很多种方法。
以下的方法就是一种。
*/

// 求x用10进制表示时的数位长度 
int len(int x){
	if(x<10) return 1;
	return len(x/10)+1;
}
	
// 取x的第k位数字
int f(int x, int k){
	if(len(x)-k==0) return x%10;
	return f(x/10,k);  //填空
}
	
int main()
{
	int x = 23574;
	printf("%d\n", f(x,3));
	return 0;
}


