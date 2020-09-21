#include <iostream>
#include <set>
#define N 5000	//׼���ҳ��������� 


using namespace std;

/*
���⣺�Ȳ�������

2,3,5,7,11,13,....���������С�
���ƣ�7,37,67,97,127,157 ������ȫ��������ɵĵȲ����У��еȲ��������С�
�ϱߵ����й���Ϊ30������Ϊ6��

2004�꣬�����뻪������������֤���ˣ��������ⳤ�ȵ������Ȳ����С�
������������һ��˵ĳɹ���

����һ����Ϊ����������������еļ�������������ĵ�������

����Ϊ10�ĵȲ������У��乫����Сֵ�Ƕ��٣�

ע�⣺��Ҫ�ύ����һ����������Ҫ��д�κζ�������ݺ�˵�����֡�

*/ 
typedef long long LL;
		
int prime[N];
LL index = 0;
set<int> all;
//�ж��Ƿ������� 
bool is_prime(int n){
	for(int i = 2;i * i <= n;i++){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}
//�ҳ����� 
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
	//ö������ 
	for(int i = 0;i < N-8;i++){
		LL first = prime[i];
		//ö�ٹ��� 
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



 
