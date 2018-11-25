#include <bits/stdc++.h>
#define MAX 100010
using namespace std;
int a[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        int n;
        cin >> n;
        cin >> a[0];
        for (int i = 1; i < n; i++)
        {
            int temp;
            cin >> temp;
            a[i] = temp - a[i - 1];
        }

        int ans = 1;
        double hou = a[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            int temp = 1;
            if (hou < a[i])
            {
                temp += a[i] / ceil(hou);
                hou = a[i] * 1.0 / temp;
            }
            else
                hou = a[i];

            ans += temp;
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}