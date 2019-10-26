#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int x;
    cin >> x;
    if (x == 5)
    {
        cout << 7;
        return 0;
    }
    cout << (x + 2) % 7;
    return 0;
}