/*
���⣺��󹫹��Ӵ�

��󹫹��Ӵ�����������ǣ�
���������������Ӵ����ܹ�ƥ���ϵ���󳤶��Ƕ��١�

���磺"abcdkkk" �� "baabcdadabc"��
�����ҵ�����Ĺ����Ӵ���"abcd",������󹫹��Ӵ�����Ϊ4��

����ĳ����ǲ��þ��󷨽������ģ���Դ��Ĺ�ģ�����������ǱȽ���Ч�Ľⷨ��

������ýⷨ��˼·������ȫ���߲���ȱʧ�Ĵ��롣
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 256
int f(const char* s1, const char* s2)
{
	int dp[N][N];
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int i,j;
	
	memset(dp,0,sizeof(int)*N*N);
	int old_max = 0;
	for(i=1; i<=len1; i++){
		for(j=1; j<=len2; j++){
			if(s1[i-1]==s2[j-1]) {
				dp[i][j] = dp[i-1][j-1]+1;
				old_max = max(dp[i][j],old_max);
			}
		}
	}
	return old_max;
}

int main()
{
	printf("%d\n", f("abcdgkkk", "baabcdgadabc"));
	return 0;
}
