如果两个整数各位数字的和是一样的，则被称为是“朋友数”，而那个公共的和就是它们的“朋友证号”。例如123和51就是朋友数，因为1+2+3 = 5+1 = 6，而6就是它们的朋友证号。给定一些整数，要求你统计一下它们中有多少个不同的朋友证号。注意：我们默认一个整数自己是自己的朋友。

输入格式：

输入第一行给出正整数N。随后一行给出N个正整数，数字间以空格分隔。题目保证所有数字小于104。

输出格式：

首先第一行输出给定数字中不同的朋友证号的个数；随后一行按递增顺序输出这些朋友证号，数字间隔一个空格，且行末不得有多余空格。

输入样例：
8
123 899 51 998 27 33 36 12
输出样例：
4
3 6 9 26

	
#include<iostream>
#include<string>
#define MAXSIEZE 50
using namespace std;


int main(void) {
	int temp[MAXSIEZE] = { 0 };
	int result[MAXSIEZE] = { 0 };
	int n;
	cin >> n;
	string num;
	string::iterator iter;
	int sum;
	while (n--) {
		sum = 0;
		cin >> num;
		for (iter = num.begin(); iter != num.end(); iter++) {
			sum += *iter - 48; //char 转换成数字相加。
		}
		temp[sum]++;		
	}
	int i,j = 0 ;
	for (i = 0; i < MAXSIEZE; i++) {
		if (temp[i] > 0) {
			result[j++] = i;
		}
	}
	cout << j << endl;
	for (i = 0; i < j-1; i++) {
		cout << result[i] << " ";
	}
	cout << result[i];
	return 0;
}