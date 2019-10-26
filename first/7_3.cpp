#include<bits/stdc++.h>
using namespace std;
int main(){
	int aMax,bMax,n;
	cin >> aMax >> bMax >> n;
	int a = aMax,b = bMax;
	for (int i = 0; i < n; ++i)
	{
		int a1,a2,b1,b2;
		cin>>a1>>a2>>b1>>b2;
		if(a2==a1+b1||b2==a1+b1)
		{
			if(a2==a1+b1&&b2==a1+b1)
				continue;
			if (a2==a1+b1)
			{
				aMax--;
			}
			else if (b2==a1+b1)
			{
				bMax--;
			}
			if (aMax<0)
			{
				
				return 0;
			}
			if (bMax<0)
			{
				printf("B\n%d", a-aMax);
				return 0;
			}
		}
	}
	return 0;

}