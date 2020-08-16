#include <iostream>
#include <cmath>
#include <climits>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <ctime>
using namespace std;
/*

标题：全球变暖

你有一张某海域NxN像素的照片，"."表示海洋、"#"表示陆地，如下所示：

.......
.##....
.##....
....##.
..####.
...###.
.......

其中"上下左右"四个方向上连在一起的一片陆地组成一座岛屿。例如上图就有2座岛屿。  

由于全球变暖导致了海面上升，科学家预测未来几十年，岛屿边缘一个像素的范围会被海水淹没。具体来说如果一块陆地像素与海洋相邻(上下左右四个相邻像素中有海洋)，它就会被淹没。  

例如上图中的海域未来会变成如下样子：

.......
.......
.......
.......
....#..
.......
.......

请你计算：依照科学家的预测，照片中有多少岛屿会被完全淹没。  

【输入格式】
第一行包含一个整数N。  (1 <= N <= 1000)  
以下N行N列代表一张海域照片。  

照片保证第1行、第1列、第N行、第N列的像素都是海洋。  

【输出格式】
一个整数表示答案。

【输入样例】
7 
.......
.##....
.##....
....##.
..####.
...###.
.......  

【输出样例】
1  



资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

注意：
main函数需要返回0;
只使用ANSI C/ANSI C++ 标准;
不要调用依赖于编译环境或操作系统的特殊函数。
所有依赖的函数必须明确地在源文件中 #include <xxx>
不能通过工程设置而省略常用头文件。

提交程序时，注意选择所期望的语言类型和编译器类型。

*/

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
char data[1001][1001];
int mark[1001][1001];
struct Point{
	int x,y;
};
int N;
int ans = 0;
void bfs(int i,int j){
	//标记已访问 
	mark[i][j] = 1;
	queue<Point> que;
	Point P;
	P.x = i;
	P.y	= j;
	que.push(P);
	int c1 = 0,c2 = 0;
	while(!que.empty()){
		//拿到头部
		Point first = que.front();
		//出队
		que.pop();
		//'#'的数量+1 
		c1++;
		//判断当前'#'周边是否有'.' 
		bool swed = false;
		for(int k = 0;k < 4;k++){
			int xn = first.x + dx[k];
			int yn = first.y + dy[k];
			if(0 <= xn && xn < N && 0 <= yn && yn < N && data[xn][yn] == '.')	swed = true;
			if(0 <= xn && xn < N && 0 <= yn && yn < N && data[xn][yn] == '#' && mark[xn][yn] == 0){
				P.x = xn;
				P.y = yn;
				que.push(P);
				mark[xn][yn] = 1;
			}
		} 
		if(swed){
			c2++;
		}	
	}
	if(c1 == c2) ++ans;		
}

void work(){
	//读入大量数据，这里采用快读配置
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cin.tie(0);
	//读取规模
	cin >> N;		
	//读换行符 
	char next;
	cin.get(next); 
	while(next != '\n') cin.get(next);
	//数据输入 
	for(int i = 0;i < N;i++){
		for(int j = 0;j < N;j++){
			cin.get(data[i][j]);
		}
		cin.get(next);
		while(next != '\n') cin.get(next);
	}
	//找#并且开始宽度优先搜索
	for(int i = 0;i < N;i++){
		for(int j = 0;j < N;j++){
			if(data[i][j] == '#' && mark[i][j] == 0){
				bfs(i,j);
			}
		}
	} 
	cout << ans << endl;
}

int main(){
	int begin = clock();
	work();
	return 0;
}



/* 

标题：日志统计

小明维护着一个程序员论坛。现在他收集了一份"点赞"日志，日志共有N行。其中每一行的格式是：

ts id  

表示在ts时刻编号id的帖子收到一个"赞"。  

现在小明想统计有哪些帖子曾经是"热帖"。如果一个帖子曾在任意一个长度为D的时间段内收到不少于K个赞，小明就认为这个帖子曾是"热帖"。  

具体来说，如果存在某个时刻T满足该帖在[T, T+D)这段时间内(注意是左闭右开区间)收到不少于K个赞，该帖就曾是"热帖"。  

给定日志，请你帮助小明统计出所有曾是"热帖"的帖子编号。  

【输入格式】
第一行包含三个整数N、D和K。  
以下N行每行一条日志，包含两个整数ts和id。  

对于50%的数据，1 <= K <= N <= 1000  
对于100%的数据，1 <= K <= N <= 100000 0 <= ts <= 100000 0 <= id <= 100000  

【输出格式】
按从小到大的顺序输出热帖id。每个id一行。  

【输入样例】
7 10 2  
0 1  
0 10    
10 10  
10 1  
9 1
100 3  
100 3  

【输出样例】
1  
3  


资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

注意：
main函数需要返回0;
只使用ANSI C/ANSI C++ 标准;
不要调用依赖于编译环境或操作系统的特殊函数。
所有依赖的函数必须明确地在源文件中 #include <xxx>
不能通过工程设置而省略常用头文件。

提交程序时，注意选择所期望的语言类型和编译器类型。



struct R{
	int ts,td;
};

bool cmp(R r1,R r2){
	return r1.ts < r2.ts;
}


int main(){
	int n,d,k;
	cin >> n >> d >> k;
	cout << n << " " << d << " " << k << endl;
	vector<R> records(n);
	map<int,int> cnt;
	for(int i = 0;i < n;i++){
		cin >> records[i].ts >> records[i].td;
	}
	vector<R>::iterator it = records.begin();
	for(;it != records.end();it++){
		cout << (*it).ts << " " << (*it).td << endl;
	}
	set<int> ans;	//记录满足条件的结果 
	//排序，自定义比较器
	sort(records.begin(),records.end(),cmp); 
	//尺取法-哨兵
	int j = 0;
	for(int i = 0;i < n;i++){
		while(j < n && records[j].ts - records[i].ts < d){//j时刻指向的指针-i时刻指向的指针
			cnt[records[j].td]++;			//该id的值加1 
			if(cnt[records[j].td] >= k){	//如果计数满足条件 
				ans.insert(records[j].td);	//将id放入ans中 
			}
			++j;
		}	
		cnt[records[i].td]--;
	} 
	set<int>::iterator i = ans.begin();
	for(;i != ans.end();i++){
		cout << *i << endl;
	}
	return 0;
} 




/* 
int main(){
	int n;
	long long ans = 0;		//考虑可能性最多的情况，N*N*N = 1 00000 00000 00000  < LONG_LONG_MAX = 9223372036854775807
	cin >> n;
	int I[n],J[n],K[n];
	for(int i = 0;i < n;i++){
		cin >> I[i];		//初始化I 
	}
	for(int i = 0;i < n;i++){
		cin >> J[i];		//初始化J 
	}
	for(int i = 0;i < n;i++){
		cin >> K[i];		//初始化K 
	}
	sort(I,I+n);			//排序,sort在头文件<algorithm>中 
	sort(J,J+n);			//排序 
	sort(K,K+n);			//排序 
	int index_min_i = 0,index_min_j = 0;	//分别记录，J和K中上次最小值的起始处，用于优化 
	for(int i = 0;i < n;i++){				//扫描I中所有元素， 
		int count1 = 0,count2 = 0;			//J中大于I[i]的值的个数和K中大于J[j]的值的个数 
		for(int j = index_min_i;j < n;j++){	//j的初始值是上次大于I[i]的下标 
			if(I[i] < J[j]){				
				index_min_i = j;			//记录当前最小下标，为了下次I[i+1]时,直接从J[index_min_i]开始扫描 
				count1 = n-j;				//记录J[j] > I[i]的个数 
				for(int k = index_min_j;k < n;k++){	//和上一个循环同理 
					if(J[j] < K[k]){
						count2 = n-k;
						index_min_j = k;
						ans += (long long)(count1*count2);	//累加答案 
						break;				
					}		
				}
				break;						//找到第一个大于I[i]的值后立马退出 
			}	
		}
	}
	cout << ans << endl;
	return 0;
}



/*
int main(){
	priority_queue<int> pque;
	pque.push(3);
	pque.push(1);
	pque.push(5);
	while(!pque.empty()){
		printf("%d\t",pque.top());
		pque.pop();
	}
	return 0;
}
*/ 
/**

	标题：测试次数
	
	x星球的居民脾气不太好，但好在他们生气的时候唯一的异常举动是：摔手机。
	各大厂商也就纷纷推出各种耐摔型手机。x星球的质监局规定了手机必须经过耐摔测试，并且评定出一个耐摔指数来，之后才允许上市流通。
	
	x星球有很多高耸入云的高塔，刚好可以用来做耐摔测试。塔的每一层高度都是一样的，与地球上稍有不同的是，他们的第一层不是地面，而是相当于我们的2楼。
	
	如果手机从第7层扔下去没摔坏，但第8层摔坏了，则手机耐摔指数=7。
	特别地，如果手机从第1层扔下去就坏了，则耐摔指数=0。
	如果到了塔的最高层第n层扔没摔坏，则耐摔指数=n
	
	为了减少测试次数，从每个厂家抽样3部手机参加测试。
	
	某次测试的塔高为1000层，如果我们总是采用最佳策略，在最坏的运气下最多需要测试多少次才能确定手机的耐摔指数呢？
	
	请填写这个最多测试次数。
	
	注意：需要填写的是一个整数，不要填写任何多余内容。

**/
/*
* n部手机测试m层，要测试m层的时候必须要从第j层去测试，j的范围为1~m。
* 每一层对应2个结果，好：剩下n部手机、剩m-j层没测;坏：剩下n-1部手机、剩j-1层没测 。 
* 因为运气最差，所有选取每一层中测试次数最多的结果作为该层的测试次数。 
* 策略最佳，从1~m层中选取测试次数最少的作为结果 
*

const int N = 1000;
int f1[N+1],f2[N+1],f3[N+1];	//分别表示1、2、3部手机在运气最差，最佳策略的情况以及n层测试中的耐摔指数 
int main(){
	//1部手机运气最差：就是1-n层分别要测1-n次
	for(int i = 1;i <= N;i++){
		f1[i] = i;
	} 
	//2部手机，对应好和坏，以及最佳策略
	for(int i = 1;i <= N;i++){
		int ans = INT_MAX;
		//2部手机i层，1~i每一层都要测试 
		for(int j = 1;j <= i;j++){
			//好和坏结果下找出测试次数最多 
			int _max = 1+max(f2[i-j],f1[j-1]);
			ans = min(ans,_max);		 
		}
		f2[i] = ans;
	} 
	//3部手机，对应好和坏，以及最佳策略
	for(int i = 1;i <= N;i++){
		int ans = INT_MAX;
		//3部手机i层，1~i每一层都要测试 
		for(int j = 1;j <= i;j++){
			//好和坏结果下找出测试次数最多 
			int _max = 1+max(f3[i-j],f2[j-1]);
			ans = min(ans,_max);		 
		}
		f3[i] = ans;
	}
	cout << f3[N] << endl;
	return 0;
}


/**
*标题：乘积尾零

	如下的10行数据，每行有10个整数，请你求出它们的乘积的末尾有多少个零？
	
	5650 4542 3554 473 946 4114 3871 9073 90 4329 
	2758 7949 6113 5659 5245 7432 3051 4434 6704 3594 
	9937 1173 6866 3397 4759 7557 3070 2287 1453 9899 
	1486 5722 3135 1170 4014 5510 5120 729 2880 9019 
	2049 698 4582 4346 4427 646 9742 7340 1230 7683 
	5693 7015 6887 7381 4172 4341 2909 2027 7355 5649 
	6701 6645 1671 5978 2704 9926 295 3125 3878 6785 
	2066 4247 4800 1578 6652 4616 1113 6205 3264 2915 
	3966 5291 2904 1285 2193 1428 2265 8730 9436 7074 
	689 5510 8243 6114 337 4096 8199 7313 3685 211 
	
	注意：需要提交的是一个整数，表示末尾零的个数。不要填写任何多余内容。

*
**
int main() {
	int n;
	int c2 = 0,c5 = 0;
	for(int i = 0;i < 100;i++){
		cin >> n;
		while(n % 2 == 0){
			c2++;
			n /= 2;
		}
		while(n % 5 == 0){
			c5++;
			n /= 5;
		}
	}
	cout << min(c2,c5) << endl;
	return 0;
}
*/
