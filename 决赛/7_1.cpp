#include <bits/stdc++.h>
using namespace std;
int toNum(string a)
{
    for (int i = 0; i < a.length(); ++i)
    {
        if (a[i] < '0' || a[i] > '9')
        {
            return 0;
        }
    }
    int res = 0;
    for (int i = 0; i < a.length(); ++i)
    {
        int t;
        t = a[i] - '0';
        res *= 10;
        res += t;
    }
    return res;
}
int main(int argc, char const *argv[])
{
    string Sa, Sb;
    cin >> Sa;
    getchar();
    getline(cin,Sb);
    int a,b;
    a = toNum(Sa);
    b = toNum(Sb);
    if (a>0&&a<=1000)
    {
        cout << a;
    }
    else
        cout << "?";
    cout << " + ";
    if (b>0&&b<=1000)
    {
        cout << b;
    }
    else
        cout << "?";
    cout << " = ";
    if (b>0&&b<=1000&&a>0&&a<=1000)
    {
        cout << a + b;
    }
    else
        cout << "?";
    return 0;
}