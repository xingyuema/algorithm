#include <iostream>
#include <set>
#define N 5000	//准备找出多少素数 


using namespace std;

/*
标题：等差素数列

2,3,5,7,11,13,....是素数序列。
类似：7,37,67,97,127,157 这样完全由素数组成的等差数列，叫等差素数数列。
上边的数列公差为30，长度为6。

2004年，格林与华人陶哲轩合作证明了：存在任意长度的素数等差数列。
这是数论领域一项惊人的成果！

有这一理论为基础，请你借助手中的计算机，满怀信心地搜索：

长度为10的等差素数列，其公差最小值是多少？

注意：需要提交的是一个整数，不要填写任何多余的内容和说明文字。

*/ 
typedef long long LL;
		
int prime[N];
LL index = 0;
set<int> all;
//判断是否是素数 
bool is_prime(int n){
	for(int i = 2;i * i <= n;i++){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}
//找出素数 
void find_prime(){
	LL t = 2;
	while(index < N){
		if(is_prime(t)){
			all.insert(t);
			prime[index++] = t;
		}		
		t++;
	}
}

int solve(){
	//枚举首项 
	for(int i = 0;i < N-8;i++){
		LL first = prime[i];
		//枚举公差 
		for(int delta = 1;delta <= prime[N-1]-first;delta++){
			int m = first;
			for(int k = 1;k < 10;k++){
				m += delta;
				if(all.find(m) == all.end()){
					break;
				}
				if(k == 9){
					return delta;
				}
			}
		}
	}
	return -1;
}

int main(){
	find_prime();
	/*
	set<int>:: iterator it = all.begin();
	for(;it != all.end();it++){
		cout << *it << endl;
	}*/
	cout << solve() << endl;
	
	return 0;
}



 
