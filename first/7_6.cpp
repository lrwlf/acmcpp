#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int odd = 0, even = 0, n, t;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        if (t % 2)
            odd++;
        else
            even++;
    }
    cout << odd << " " << even;
    return 0;
}