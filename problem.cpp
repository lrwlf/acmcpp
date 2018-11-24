#include <bits/stdc++.h>
#define MAX 200001
using namespace std;
struct node
{
    int v;
    struct node *l;
    struct node *r;
    node()
    {
        l = NULL;
        r = NULL;
    }
};
struct node *tre;
void ins(int x)
{
    node *tnode = new node();
    tnode->v = x;
    if (tre == NULL)
        tre = tnode;
    else
    {
        dfs(tre, node);
    }
    delete tnode;
}
void dfs(node *t, node *p)
{
}   
int a[MAX];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        tre = NULL;
    }
    return 0;
}