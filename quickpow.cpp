#include <bits/stdc++.h>
#define MAX 100001
#define ll long long
#define mod 998244353
using namespace std;
ll a[2][MAX];
ll quickpow(ll a, ll b)
{
    ll s = 1;
    while (b > 0)
    {
        if (b % 2)
            s = (s * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return s;
}
int main()
{
    ios::sync_with_stdio(false);
    ll t;
    cin >> t;
    ll n, m;
    while (t--)
    {
        memset(a, 0, sizeof(a));
        cin >> n >> m;
        for (ll i = 0; i < m; i++)
        {
            ll t1, t2, t3;
            cin >> t1 >> t2 >> t3;
            a[t3 - 2][t1]++;
            a[t3 - 2][t2 + 1]--;
        }
        miner[0] = a[0][1];
        miner[1] = a[1][1];
        for (int i = 2; i <= n; i++)
        {
            a[0][i] += a[0][i - 1];
            a[1][i] += a[1][i - 1];
            miner[0] = min(miner[0], a[0][i]);
            miner[1] = min(miner[1], a[1][i]);
        }
        ll ans = (quickpow(2, miner[0]) % mod) * (quickpow(3, miner[1]) % mod);
        cout << ans % mod << endl;
    }
    return 0;
}