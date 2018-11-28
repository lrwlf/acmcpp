#include <bits/stdc++.h>
#define MAX 1010
using namespace std;
int n, m;
int a[MAX][MAX];
int mark[MAX];
int ans = 1;
int deg[MAX];
void dfs(int x)
{
    mark[x] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[x][i] == 1 && mark[i] == 0)
            dfs(i);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int k = 0; k < m; k++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        a[t1][t2] = 1;
        a[t2][t1] = 1;
        deg[t1]++;
        deg[t2]++;
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        if (mark[i] == 0)
        {
            cout << 0 << endl;
            return 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (deg[i]%2!=0)
            {
                ans = 0;
                break;
            }
    }

    cout << ans << endl;
    return 0;
}