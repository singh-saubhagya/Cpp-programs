#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'

lli n,m;
vector<lli> arr;
vector<vector<lli>> t;
/*
1 ->max
2 ->l sum
3 ->r sum
4 ->sum
5 -> 
*/
void build(lli id,lli l,lli r)
{
    if(l==r)
    {
        t[id][1]=arr[l];
        t[id][2]=arr[l];
        t[id][3]=arr[l];
        t[id][4]=arr[l];
        return ;
    }
    lli mid=l+(r-l)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    t[id][1]=max(t[2*id][1],max(t[2*id+1][1],t[2*id][3]+t[2*id+1][2]));
    t[id][2]=max(t[2*id][2],t[2*id][4]+t[2*id+1][2]);
    t[id][3]=max(t[2*id+1][3],t[2*id][3]+t[2*id+1][4]);
    t[id][4]=t[2*id][4]+t[2*id+1][4];
    return;
}
void update(lli id, lli l ,lli r, lli pn , lli val)
{
    if(pn<l || pn>r )
    return ;

    if(l==r)
    {
        arr[pn]=val;
        t[id][1]=arr[l];
        t[id][2]=arr[l];
        t[id][3]=arr[l];
        t[id][4]=arr[l];
        return ;
    }
    lli mid=l+(r-l)/2;
    update(2*id,l,mid,pn,val);
    update(2*id+1,mid+1,r,pn,val);
    t[id][1]=max(t[2*id][1],max(t[2*id+1][1],t[2*id][3]+t[2*id+1][2]));
    t[id][2]=max(t[2*id][2],t[2*id][4]+t[2*id+1][2]);
    t[id][3]=max(t[2*id+1][3],t[2*id][3]+t[2*id+1][4]);
    t[id][4]=t[2*id][4]+t[2*id+1][4];
    return ;
}
lli answerquery()
{
    return t[1][1];
}
void solve()
{
    cin>>n>>m;
    t=vector<vector<lli>>(4*n,vector<lli>(10,0));
    arr.resize(n+2);
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];    
    }
    build(1,1,n);

    for(int i=0;i<m;i++)
    {
        lli pn,val;
        cin>>pn>>val;
        update(1,1,n,pn,val);
        lli ans=answerquery();
        if(ans<0)
        ans=0;

        cout<<ans<<endl;

    }
}
signed main()
{
    solve();
}