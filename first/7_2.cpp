#include<bits/stdc++.h>
using namespace std;
int main(){
	int hour,minute,n = 0;
	scanf("%d:%d",&hour,&minute);
	n = hour - 12;
	if (minute)
		n++;
	if(n<=0)
		printf("Only %02d:%02d.  Too early to Dang.", hour,minute);
	else
		for (int i = 0; i < n; ++i)
			printf("Dang");
	return 0;

}