#include <iostream>
#include <vector>
using namespace std;
int m,n;
vector<int> mp[10001];
vector<int> newmp[10001];
int dfn[10001],low[10001],stk[10001];
bool v[10001];
int cnt = 0,t = 0,cntnew = 0;
void tarjan(int now)
{
    dfn[now] = low[now] = ++cnt;
    stk[++t] = now;
    v[now] = 1;
    for(int i = 0; i<mp[now].size(); ++i)
    {
        int temp = mp[now][i];
        if(!dfn[temp])
        {
            tarjan(temp);
            low[now] = min(low[now],low[temp]);
        }
        else if(v[temp])
        {
            low[now] = min(low[now],dfn[temp]);
        }
    }
    if(dfn[now]==low[now])
    {
        int cur;
        do
        {
            cur=stk[t--];
            v[cur]=false;
            newmp[cntnew].push_back(cur);
//           cout<<cur<<" ";
        }
        while(now!=cur);
        cntnew++;
//       cout<<endl;
    }
}
bool hasOut(int x)
{
    vector<int> ls = newmp[x];
    bool mark[10001] = {0};
    for(int i = 0; i<ls.size(); ++i)
    {
        mark[ls[i]]=1;
    }
    for(int i = 0; i<ls.size(); ++i)
    {
        int t = ls[i];
        for(int j = 0; j<mp[t].size(); ++j)
        {
            if(!mark[mp[t][j]])
            {
                return 1;
            }
        }
    }
    return 0;
}
int getans()
{
    int res = 0,num=0;

    for(int i = 0; i<cntnew; ++i)
    {
        if(!hasOut(i))
        {
            res=max(res,(int)newmp[i].size());
            num++;
            if(num>1)
                return 0;
        }
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i = 0; i<m; ++i)
    {
        int t1,t2;
        cin>>t1>>t2;
        mp[t1].push_back(t2);
    }
    for(int i = 1; i<=n; ++i)
    {
        if(!dfn[i])
            tarjan(i);
    }
    cout<<getans();
    return 0 ;
}
