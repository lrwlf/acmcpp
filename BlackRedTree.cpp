#include <bits/stdc++.h>
#define MAX 33
using namespace std;
struct node
{
    int v;
    node *l;
    node *r;
};
void build(node *&n, int v) //root的别名，直接对root指针操作
{
    if (n == NULL)
    {
        n = new node();
        n->l = NULL;
        n->r = NULL;
        n->v = v;
        return;
    }
    else if (abs(n->v) <= abs(v))
        build(n->l, v);
    else
        build(n->r, v);
}

void dfs(node *root, int t, int &black)
{
    if (root == NULL)
    {
        if (black == -1)
            black = t;
        else if (black != t)
            black = -2;
        return;
    }
    if (black == -2)
        return;
    if (root->v > 0)
        t++;
    dfs(root->l, t, black);
    dfs(root->r, t, black);
}
bool bfs(node *root)
{
    queue<node *> q;
    q.push(root);
    if (root->v < 0)
        return false;
    while (!q.empty())
    {
        node *top = q.front();
        q.pop();
        int black = -1;
        dfs(top, 0, black);
        if (black == -2)
            return false;
        if (top->l != NULL)
        {
            if (top->v < 0 && top->l->v < 0)
                return false;
            else
                q.push(top->l);
        }
        if (top->r != NULL)
        {
            if (top->v < 0 && top->r->v < 0)
                return false;
            else
                q.push(top->r);
        }
    }
    return true;
}
int main()
{
    int k;
    cin >> k;
    while (k--)
    {
        int n;
        cin >> n;
        node *tree = NULL;
        for (int i = 0; i < n; i++)
        {
            int t;
            cin >> t;
            build(tree, t);
        }
        if (bfs(tree) == true)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
