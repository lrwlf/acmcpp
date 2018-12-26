#include<bits/stdc++.h>
#define ll long long
#define MAX 10010
using namespace std;
int n;
int edge[MAX][MAX];
int dis[MAX];
int mk[MAX];
void dijkstra(int v)
{
    for(int i=0; i<n; i++)
    {
        if(i!=v)
        {
            dis[i] = edge[v][i];
        }
    }
    mk[v] = 1;
    for(int i=1; i<n; i++)
    {
        int mins = INT_MAX;
        int u = v;
        for(int j=0; j<n; ++j)
            if(!mk[j]&&dis[j]<mins)
            {
                u=j;
                mins=dis[j];
            }
        mk[u] = 1;
        for(int j=0; j<n; j++)
            if(!mk[i]&&edge[u][j]<INT_MAX)
            {
                if(dis[u]+edge[u][j]<dis[j])
                {
                    dis[j] = dis[u]+edge[u][j];
                }
            }

    }
}
int main()
{
    scanf("%d",&n);
    for(int i = 0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d",&edge[i][j]);
            if(edge[i][j]<0)
            {
                printf("not possible");
                return 0;
            }
            else if(edge[i][j]==0&&i!=j)
                edge[i][j] = INT_MAX;
        }
    }
    dijkstra(0);
    for(int i = 0; i<n; i++)
    {
        if(i!=0)
            printf(" ");
        printf("%d",dis[i]);
    }
    return 0;
}
