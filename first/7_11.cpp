#include <bits/stdc++.h>
using namespace std;
struct Tree
{
    int data;
    Tree *lchild;
    Tree *rchild;
};
int n;
int pre[31], mid[31];
string res = "";
Tree *creatTree(int pre[],int mid[],int n)
{
    if(n==0)
        return NULL;
    Tree *t = (Tree *)malloc(sizeof(Tree));
    t->data = pre[0];
    int pos;
    for(pos = 0; pos<n; pos++)
    {
        if(pre[0]==mid[pos])
            break;
    }
    t->rchild = creatTree(pre+1,mid,pos);
    t->lchild = creatTree(pre+pos+1,mid+pos+1,n-pos-1);
    return t;
}
void Trans(Tree *t)
{
    Tree *x;
    x = t->lchild;
    t->lchild = t->rchild;
    t->rchild = x;
    if (t->rchild)
    {
        Trans(t->rchild);
    }
    if (t->lchild)
    {
        Trans(t->lchild);
    }
}
void preOut(Tree *t)
{
    queue<Tree*> q;
    q.push(t);
    while(!q.empty())
    {
        Tree* temp = q.front();
        if(temp->lchild)
            q.push(temp->lchild);
        if(temp->rchild)
            q.push(temp->rchild);
        int it = temp->data;
        string st = "";
        while(it)
        {
            st+=it%10+'0';
            it/=10;
        }
        reverse(st.begin(), st.end());
        res+=st;
        res+=' ';
        q.pop();
    }
}
int main(int argc, char const *argv[])
{
//    freopen("./in","r",stdin);
 //   freopen("./out","w",stdout);`
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> mid[i];
    for (int i = 0; i < n; ++i)
        cin >> pre[i];

    Tree *t = creatTree(pre,mid,n);
//    Trans(t);
    preOut(t);
    cout << res.substr(0,res.length()-1);
    return 0;
}
