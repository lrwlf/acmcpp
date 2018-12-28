#include <bits/stdc++.h>
#define ll long long
#define MAX 10010
using namespace std;
int n,p;
bool mark[MAX];
bool markv[1000010];
int hashlist[MAX];
ll gethash(ll x)
{
    ll loc = x%p;
    if(loc == p-1&&mark[loc])
        loc = 0;
    while(mark[loc])
        loc++;
    mark[loc] = 1;
    return loc;
}
ll findx(ll x)
{
    ll loc;
    loc = x%p;
    while(hashlist[loc]!=x)
    {
       loc++;
       if(loc == p)
        loc = 0;
    }
    return loc;
}
int main()
{
    cin >> n>>p;
    for(int i=0; i<n; i++)
    {
        ll t;
        cin>>t;
        if(markv[t])
            cout<<findx(t);
        else
        {
            markv[t] = 1;
            ll l = gethash(t);
            hashlist[l] = t;
            cout<<l;
        }
        if(i!=n-1)
            cout<<" ";

    }

    return 0;
}
