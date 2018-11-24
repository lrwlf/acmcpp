#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int len;
        string s;
        cin >> len >> s;
        int i = 0, j = 1, k = 0;
        while (i < len && j < len && k < len)
        {
            if (i == j)
                j++;
            if (s[(i + k) % len] == s[(j + k) % len])
                k++;
            else if (s[(i + k) % len] < s[(j + k) % len])
            {
                j = j + k + 1;
                k = 0;
            }
            else
            {
                i = i + k + 1;
                k = 0;
            }
        }
        cout << min(i, j) << endl;
    }
    return 0;
}