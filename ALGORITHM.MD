
## 1.字符串，BFS
题目描述  
玛雅人有一种密码，如果字符串中出现连续的2012四个数字就能解开密码。给一个长度为N的字符串（2=<N<=13），该字符串中只含有0,1,2三种数字，问这个字符串要移位几次才能解开密码，每次只能移动相邻的两个数字。例如02120经过一次移位，可以得到20120,01220,02210,02102，其中20120符合要求，因此输出为1.如果无论移位多少次都解不开密码，输出-1。

输入描述：第一行输入N，第二行输入N个数字，只包含0，1，2  
输入：  
5  
02120  
5  
02120  
输出：  
1  
1  
```
#include <iostream>
#include<string>
#include<stack>
#include<cstring>
#include<map>
#include<queue>
#include <algorithm>
using namespace std;
const int maxn = 110;

map<string, int>mp;//表示这是第几次交换而得到的string
queue<string>que;
int BFS(string str) {
	mp.clear();
	while (!que.empty())
		que.pop();
	que.push(str);
	mp[str] = 0;
	while (!que.empty()) {
		string currStr = que.front();
		que.pop();
		for (int i = 0; i < str.length() - 1; i++) {
			string nextStr = currStr;
			swap(nextStr[i], nextStr[i + 1]);
			if (mp.find(nextStr) == mp.end()) {
				//交换之后这是一个新字符串
				mp[nextStr] = mp[currStr] + 1; //在原字符串交换次数的基础上增加
				if (nextStr.find("2012", 0) != string::npos)
					return mp[nextStr];
				else
					que.push(nextStr);
			}
			else continue;
		}
	}
	return -1;
}

int main() {
	int n,ans;
	string str, str1 = "02012", str2 = "20120";
	while (scanf("%d", &n) != EOF) {
		cin >> str;
		int t = str.find("2012", 0);
		if (t != string::npos)
			printf("0\n");
		else {
			ans = BFS(str);
			printf("%d\n", ans);
		}
	}
	return 0;
}
```
## 2.字符串
![输出](http://ss1.sinaimg.cn/large/005VVqRPly1g0zx9ecwgnj30gi0frmxx.jpg)


