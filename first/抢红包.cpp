#include<bits/stdc++.h>
#define MAX 10001
using namespace std;
struct per
{
	int num;
	double moneny;
	int geshu;
}li[MAX];
bool cmp(per a,per b){
	return a.moneny != b.moneny ? a.moneny>b.moneny : a.geshu!=b.geshu ? a.geshu>b.geshu:a.num<b.num;
/*	if(a.moneny!=b.moneny)
        return a.moneny>b.moneny;
    if(a.geshu!=b.geshu)
        return a.geshu>b.geshu;
    else
        return a.num<b.num;*/
}
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		li[i].num = i+1;
		li[i].moneny=0;
        li[i].geshu = 0;
	}
	for(int i=0;i<n;i++)
	{
		int k;
		cin>>k;
		for(int j=0;j<k;j++)
		{
			int m,p;
			cin >> m >> p;
			li[m-1].moneny+=p;
			li[m-1].geshu++;
			li[i].moneny-=p;
		}
	}
	sort(li,li+n,cmp);
	for(int i =0;i<n;i++){
		printf("%d %.2f\n",li[i].num,li[i].moneny/100);
	}
	return 0;
}
