#include<iostream>
#define Max 101
using namespace std;
char str1[Max],str2[Max];
int AnswerCorrect(char a[],char b[],int m)
{
    if(m==0)
    {
        return 0;
    }
    int i;
    for(i=0;i<m;i++)
    {
        if(b[i]==a[0])
        {
             break;
        }
    }
    int c= AnswerCorrect(a+1,b,i)+1;
    int d= AnswerCorrect(a+i+1,b+i+1,m-i-1)+1;
    return c>d?c:d;
}
int main()
{
    int n;
    cin>>n;
    cin>>str1>>str2;
    cout<< AnswerCorrect(str1,str2,n)<<endl;
    return 0;
 
}
