#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int gplt[4] = {0};
    char c;
    while((c = getchar()) != '\n')
    {
        switch(c)
        {
        case 'g':
            gplt[0]++;
            break;
        case 'G':
            gplt[0]++;
            break;
        case 'p':
            gplt[1]++;
            break;
        case 'P':
            gplt[1]++;
            break;
        case 'l':
            gplt[2]++;
            break;
        case 'L':
            gplt[2]++;
            break;
        case 't':
            gplt[3]++;
            break;
        case 'T':
            gplt[3]++;
            break;
        default:
            break;
        }
    }
    while(gplt[0] > 0 || gplt[1] > 0 || gplt[2] > 0 || gplt[3] > 0)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (gplt[i] > 0)
            {
                gplt[i]--;
                switch(i)
                {
                case 0:
                    cout << 'G';
                    break;
                case 1:
                    cout << 'P';
                    break;
                case 2:
                    cout << 'L';
                    break;
                case 3:
                    cout << 'T';
                    break;
                }
            }
        }
    }
    return 0;

}