#include <bits/stdc++.h>
#define MAX 33
using namespace std;
struct node
{
    int v;
    node *l;
    node *r;
};
void build(node *n, int v)
{
    if (n == NULL)
    {
        n = new node(); 
        n->l = NULL;
        n->r = NULL;
        n->v == v;
        return;
    }
    else if (abs(n->v) < v)
        build(n->l, v);
    else
        build(n->r, v);
}
void dfs(node *root)
{
    cout << root->v << endl;
    if (root->r != NULL)
        dfs(root->r);
    if (root->l != NULL)
        dfs(root->l);
}
int main()
{
    int k;
    cin >> k;
    while(k--)
    {
        int n;
        cin >> n;
        
        for(int i = 0;i<n;i++)
        {
            int t;
            cin >> t;
            build()
        }
    }
    return 0;   
}
