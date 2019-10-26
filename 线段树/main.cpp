#include<bits/stdc++.h>
#define ll long long
#define MAXN 100001
using namespace std;

ll tree[MAXN<<2],ls[MAXN],tag[MAXN<<2];
int lc(int x){return x<<1;}
int rc(int x){return x<<1|1;}
void push_up(int x){
    tree[x] = tree[lc(x)]+tree[rc(x)];
}
void f(ll p,ll l,ll r,ll k)
{
    tag[p]=tag[p]+k;
    tree[p]=tree[p]+k*(r-l+1);
}
void push_down(int x,int l,int r){
    int mid=(l+r)>>1;
    f(lc(x),l,mid,tag[x]);
    f(rc(x),mid+1,r,tag[x]);
    tag[x]=0;

}
void build(ll x,int l,int r){
    if(l==r){
        tree[x] = ls[l];
        return;
    }
    int mid = (l+r)>>1;
    build(lc(x),l,mid);
    build(rc(x),mid+1,r);
    push_up(x);
    //调用build(1,1,n);
}
void upgrade(int lx,int rx,int l,int r, int x,int val){
    if(lx<=l && rx>=r){
        tree[x] += val*(r-l+1);
        tag[x]+=val;
        return;
    }
    push_down(x,l,r);
    ll mid=(l+r)>>1;
    if(lx<=mid)upgrade(lx,rx,l,mid,lc(x),val);
    if(rx>mid) upgrade(lx,rx,mid+1,r,rc(x),val);
    push_up(x);
}
ll query(int ql,int qr,int l,int r,int x){
    ll res = 0;
    if(ql<=l&&r<=qr) return tree[x];
    ll mid=(l+r)>>1;
    push_down(x,l,r);
    if(ql<=mid)res+=query(ql,qr,l,mid,lc(x));
    if(qr>mid) res+=query(ql,qr,mid+1,r,rc(x));
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n>>m;
    for(int i = 1;i<=n;++i){
        cin>>ls[i];
    }
    build(1,1,n);
    for(int i = 0;i<m;++i){
        int op;
        cin >> op;
        if(op == 1){
            int lx,rx,val;
            cin>>lx>>rx>>val;
            upgrade(lx,rx,1,n,1,val);
        }
        else{
            int l,r;
            cin>>l>>r;
            cout<<query(l,r,1,n,1)<<endl;
        }
    }
    return 0;
}
