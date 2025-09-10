#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
// where to use lazy segment tree refer to image in mobile


lli n;
vector<int> arr;

struct node{
    int sum,mx,lazy;

    node()
    {
        sum=0;
        mx=0;
        lazy=0;
    }
};
vector<node> t;


node combine(int id1,int id2)
{
    node temp;
    temp.sum=t[id1].sum+t[id2].sum;
    temp.mx=max(t[id1].mx,t[id2].mx);
    return temp;
}
void build(int id,int l,int r)
{
    if(l==r)
    {
        t[id].mx=arr[l];
        t[id].sum=arr[l];
        t[id].lazy=0;
        return;
    }

    int mid=l+(r-l)/2;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    t[id]=combine(id<<1,id<<1|1);
}
void push(int id,int val,int l,int r)
{
    if(!t[id].lazy)
    return ; 
    t[id].sum=val*(r-l+1);
    t[id].mx=val;
    arr[l]=val;
    t[id<<1].lazy=val;
    t[id<<1|1].lazy=val;
    t[id].lazy=0;
    return ;
}
void update(int id,int l,int r,int ll,int rr,int val)
{
    push(id,val,l,r);
    if(l>rr || r<ll)
    return ;
    
    if(l>=ll && r<=rr)
    {
        t[id].lazy=val;
        arr[l]=val;
        push(id,val,l,r);
        return ;

    }
    int mid=l+(r-l)/2;
    update(id<<1,l,mid,ll,rr,val);
    update(id<<1|1,mid+1,r,ll,rr,val);
    t[id]=combine(id<<1,id<<1|1);
}

void solve()
{
    cin>>n;
    arr.resize(n+2);
    for(int i=1;i<=n;i++)
    cin>>arr[i];
    t.resize(4*n);
    build(1,1,n);
    update(1,1,n,3,5,10);
    update(1,1,n,1,3,7);

}
signed main()
{
  cin.tie(0); cout.tie(0);
  solve();
}