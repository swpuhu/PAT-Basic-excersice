����ѧ�У�����ġ��װ뾶����ָ������ֵ��ģ���ϵ���ȷ�硣����֮�����ڸ�����n�������ռ������ֵ{a1+b1i, ..., an+bni}�����ǵ�ģΪʵ�����鲿��ƽ���͵Ŀ����������װ뾶���������ģ��

���ڸ���һЩ�����ռ������ֵ��������㲢�����Щ����ֵ���װ뾶��

�����ʽ��

�����һ�и���������N��<= 10000�������������ֵ�ĸ��������N�У�ÿ�и���1������ֵ��ʵ�����鲿������Կո�ָ���ע�⣺��Ŀ��֤ʵ�����鲿��Ϊ����ֵ������1000��������

�����ʽ��

��һ��������װ뾶���������뱣��С�����2λ��

����������
5
0 1
2 0
-1 0
3 3
0 -3
���������
4.24


#include<iostream>
#include<math.h>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	int a, b;
	double thisRadius;
	double maxRadius = 0;
	while (n-- > 0) {
		cin >> a >> b;
		thisRadius = sqrt((a*a + b*b));
		if (thisRadius > maxRadius) {
			maxRadius = thisRadius;
		}
	}
	printf("%.2lf", maxRadius);
	return 0;
}