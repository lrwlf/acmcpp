#include <bits/stdc++.h>
using namespace std;
int q[1000001];
bool mark[1000001];
int main()
{
    string noRes = "No one is handsome";
    string outPut = "";
    int n, sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j)
        {
            int x;
            cin >> x;
            q[x] += k - 1;
        }
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int t;
        cin >> t;
        if(q[t] == 0 && !mark[t])
        {
            if(sum != 0)
                cout << " ";
            printf("%05d", t);
            sum++;
            mark[t] = 1;
        }
    }
    if(sum == 0)
        cout << noRes;

    return 0;
}
