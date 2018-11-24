#include <iostream>
#include <string>
using namespace std;
void getNext(string s,                                      
    int j = 0, k = -1;
    int len = s.length();
    next[0] = -1;
    while (j < len - 1)
    {
        if (k == -1 || s[j] == s[k])
        {
            next[++j] = ++k;
        }
        else
            k = next[k];                                                                                                                
    }
}
int kmp(string parents, string child)
{
    int plen = parents.length();
    int clen = child.length();
    if (plen < clen)
        return -1;
    int *next = new int[clen];
    getNext(child, next);
    int i = 0, j = 0;
    while (i < plen && j < clen)
    {
        if (j == -1 || parents[i] == child[j])
        {
            i++;
            j++;
        }
        else
            j = next[j];
    }
    delete next;
    if (j == clen)
        return i - j;
    return -1;
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << kmp(s1, s2) << endl;
    return 0;
}
