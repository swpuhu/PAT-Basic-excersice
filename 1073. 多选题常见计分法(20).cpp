1073. 多选题常见计分法(20)

批改多选题是比较麻烦的事情，有很多不同的计分方法。有一种最常见的计分方法是：如果考生选择了部分正确选项，并且没有选择任何错误选项，则得到50%分数；如果考生选择了任何一个错误的选项，则不能得分。本题就请你写个程序帮助老师批改多选题，并且指出哪道题的哪个选项错的人最多。

输入格式：

输入在第一行给出两个正整数N（<=1000）和M（<=100），分别是学生人数和多选题的个数。随后M行，每行顺次给出一道题的满分值（不超过5的正整数）、选项个数（不少于2且不超过5的正整数）、正确选项个数（不超过选项个数的正整数）、所有正确选项。注意每题的选项从小写英文字母a开始顺次排列。各项间以1个空格分隔。最后N行，每行给出一个学生的答题情况，其每题答案格式为“(选中的选项个数 选项1 ……)”，按题目顺序给出。注意：题目保证学生的答题情况是合法的，即不存在选中的选项数超过实际选项数的情况。

输出格式：

按照输入的顺序给出每个学生的得分，每个分数占一行，输出小数点后1位。最后输出错得最多的题目选项的信息，格式为：“错误次数 题目编号（题目按照输入的顺序从1开始编号）-选项号”。如果有并列，则每行一个选项，按题目编号递增顺序输出；再并列则按选项号递增顺序输出。行首尾不得有多余空格。如果所有题目都没有人错，则在最后一行输出“Too simple”。

输入样例1：
3 4 
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 a c) (3 b d e) (2 a c) (3 a b e)
(2 a c) (1 b) (2 a b) (4 a b d e)
(2 b d) (1 e) (1 c) (4 a b c d)
输出样例1：
3.5
6.0
2.5
2 2-e
2 3-a
2 3-b
输入样例2：
2 2 
3 4 2 a c
2 5 1 b
(2 a c) (1 b)
(2 a c) (1 b)
输出样例2：
5.0
5.0
Too simple




#include<iostream>  
#include<set>  
using namespace std;  
int main()  
{  
    set<char> v[1001];  
    char a;  
    int n,m,i,j,x,y,max=0,p[101][5]={0};  
    double score[101];  
    cin>>n>>m;  
    for(i=0;i<m;i++)  
    {  
        cin>>score[i]>>x>>y;  
        while(y--)  
        {  
            scanf(" %c",&a);  
            v[i].insert(a);  
        }  
    }  
    while(n--)  
    {  
        double sum=0;  
        scanf("\n");  
        for(i=0;i<m;i++)  
        {  
            int flag=1;  
            set<char>s,g=v[i];  
            set<char>::iterator it,ot;  
            if(i!=0) scanf(" ");  
            scanf("(%d",&x);  
            while(x--)  
            {  
                scanf(" %c",&a);  
                s.insert(a);  
            }  
            scanf(")");  
            if(s==v[i]) sum=sum+score[i]; //如果选择与正确答案完全一致，则得到该题全部分数。  
            else //否则，需判断是否有错选的选项，若有，不得分，若无，得该题一半分数。  
            {  
                for(it=s.begin();it!=s.end();it++) //遍历该题有无错选的选项。  
                {  
                    if(v[i].find(*it)==v[i].end())  
                    {  
                        flag=0; //如果选择的选项不属于正确选项，用flag=0做标记。  
                        p[i][*it-'a']++; //统计错选选项出现次数。  
                        if(p[i][*it-'a']>max)  
                            max=p[i][*it-'a'];  
                    }  
                }  
                for(ot=g.begin();ot!=g.end();ot++) //遍历该题有无漏选的选项。  
                {  
                    if(s.find(*ot)==s.end())  
                    {  
                        p[i][*ot-'a']++; //统计漏选选项出现次数。  
                        if(p[i][*ot-'a']>max)  
                            max=p[i][*ot-'a'];  
                    }  
                }  
                if(flag==1) sum=sum+score[i]/2.0; //如果flag=1,说明未有错选的选项(只是漏选),可得该题一半分数。  
            }  
        }  
        printf("%.1f\n",sum);  
    }  
    if(max==0) puts("Too simple");  
    else  
    {  
        for(i=0;i<m;i++)  
        {  
            for(j=0;j<5;j++)  
            {  
                if(p[i][j]==max)  
                    printf("%d %d-%c\n",max,i+1,j+'a');  
            }  
        }  
    }  
    return 0;  
}  