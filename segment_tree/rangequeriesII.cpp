#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
lli n;lli q;
vector<lli> arr;
vector<lli> t;
void build(lli id,lli l,lli r)
{
    if(l==r)
    {
        t[id]=0;
        return ; 
    }
    lli mid=l+(r-l)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    
}
void update(lli id,lli l,lli r , lli ll,lli rr, lli val)
{
    if(r<ll || l>rr)
    return ;

    if(l==r)
    {
        arr[l]=arr[l]+val;
        return ;
    }
    if(ll<=l && rr>=r)
    {
        t[id]+=val;
        return;
    }
    lli mid=l+(r-l)/2;
    update(2*id,l,mid,ll,rr,val);
    update(2*id+1,mid+1,r,ll,rr,val);

}
lli answerquery(lli id,lli l, lli r, lli pn)
{
    if(pn<l || pn>r)
    {
        return 0;
    }
    if(l==r)
    {
        return arr[l];
    }
    int mid=l+(r-l)/2;
    if(pn<=mid)
    {
        return t[id]+answerquery(2*id,l,mid,pn);
    }
    else 
    {
        return t[id] + answerquery(2*id+1,mid+1,r,pn);
    }
}
void solve()
{
    cin>>n>>q;
    arr.resize(n+2);
    t.resize(4*n);
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    build(1,1,n);
    while(q--)
    {
        lli t; cin>> t;
        if(t==1)
        {
            lli a,b,c;
            cin>>a>>b>>c;
            update(1,1,n,a,b,c);
        }
        else if(t==2)
        {
            lli pn;
            cin>>pn;
            cout<<answerquery(1,1,n,pn)<<endl;
        }
    }
}
signed main()
{
  cin.tie(0); cout.tie(0);
  solve();
}