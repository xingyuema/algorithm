#include <iostream>
#include <set>
#include <sstream>

using namespace std;

void i2s(int i,string &s){
	stringstream ss;
	ss << i;
	ss >> s;
}

bool is_leap(int a){
	return ((a % 100 != 0 && a % 4 == 0)) || (a % 400 == 0);
}

string solve(int a,int b,int c){
	//先判断年 
	if(a >= 0 && a <= 59)	a += 2000;
	else if(a >= 60 && a <= 99)	a += 1900;
	else
		return "";
	//判断月
	if(b < 1 || b > 12)	return "";
	//判断日
	if(c < 1 || c > 31)	return ""; 
	
	//判断是否是闰年 
	bool leap = is_leap(a);
	
	//进一步判断日期合法性 
	switch(b){
		case 2:
			if(is_leap(a) && c > 29)	return "";
			if(!is_leap(a) && (c > 28))	return "";
			break;
		case 4:
			if(c > 30)	return "";
		case 6:
			if(c > 30)	return "";
		case 9:
			if(c > 30)	return "";
		case 11:
			if(c > 30)	return "";
		default:
			break;			
	}
	
	string _a,_b,_c;
	i2s(a,_a);
	i2s(b,_b);
	i2s(c,_c);
	if(_b.length() == 1){
		_b = '0'+_b;
	}
	if(_c.length() == 1){
		_c = '0'+_c; 
	}
	return _a+'-'+_b+'-'+_c;
}



int main(){
	string info;
	cin >> info;
	int a,b,c;
	a = (info[0]-'0')*10+(info[1]-'0');
	b = (info[3]-'0')*10+(info[4]-'0');
	c = (info[6]-'0')*10+(info[7]-'0');
	string _case1 = solve(a,b,c);
	string _case2 = solve(c,b,a);
	string _case3 = solve(c,a,b);
	
	set<string> all;
	
	if(_case1.length() != 0){
		all.insert(_case1);
	}
	if(_case2.length() != 0){
		all.insert(_case2);
	}
	if(_case3.length() != 0){
		all.insert(_case3);
	}
	for(set<string>::iterator it = all.begin();it != all.end();it++){
		cout << *it << endl;
	}
	
	
	return 0;
}


