#include <bits/stdc++.h>
using namespace std;
int rel[110][110];
bool mark[110];
int n, m, k;
bool isFriend(int a, int b)
{
    mark[a] = true;
    if (rel[a][b] == 1)
        return true;
    for (int i = 1; i <= n; ++i)
    {
        if (!mark[i] && rel[a][i]==1 && isFriend(i, b)) //if(rel[a][i]&&rel[i][b])
        	
        {
            return true;
        }
    }
    return false;
}
bool isEnemy(int a, int b)
{
    if (rel[a][b] == -1)
    {
        return true;
    }
    return false;
}
int main(int argc, char const *argv[])
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i)
    {
        int x1, x2, x3;
        cin >> x1 >> x2 >> x3;
        rel[x1][x2] = x3;
        rel[x2][x1] = x3;
    }
    for (int i = 0; i < k; ++i)
    {
        int a, b;
        cin >> a >> b;
        bool f, e;
        f = isFriend(a, b);
        e = isEnemy(a, b);
        memset(mark, 0, sizeof(mark));
        if (f)
        {
            if(!e)
                cout << "No problem"<<endl;
            else
            {
                cout << "OK but..."<<endl;
            }
        }
        else
        {
            if (!e)
            {
                cout << "OK"<<endl;
            }
            else
            {
                cout << "No way"<<endl;
            }
        }


    }
    return 0;
}