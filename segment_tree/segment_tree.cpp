#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
int n;
int arr[100100];
int t[400100];

// the build and update tree and answerquery takes logn time.
void build(int id,int l,int r)
{
    if(l==r)
    {
        t[id]=arr[l];
        return;
    }
    int mid=l+(r-l)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    t[id]=t[2*id]+t[2*id+1];
    return ;
}
void updatetree(int id,int l, int r,int pos,int val)
{
    if(pos<l || pos>r)
    return ;
    if(l==r)
    {
        arr[l]=val;
        t[id]=val;
        
        return; 
    }

    int mid=l+(r-l)/2;
    updatetree(2*id,l,mid,pos,val);
    updatetree(2*id+1,mid+1,r,pos,val);
    t[id]=t[2*id]+t[2*id+1];
}
int answerquery(int id,int l,int r, int ll,int rr)
{
    if(r<ll || l>rr)
    return 0;

    if(ll<=l && rr>=r)
    return t[id];

    int mid=l+(r-l)/2;
    int ans=answerquery(2*id,l,mid,ll,rr)+answerquery(2*id+1,mid+1,r,ll,rr);
    return ans;

}
void solve()
{
    cin>>n;
    
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    build(1,1,n);
    int q;
    cin>>q;
    while(q--)
    {
        char ch;
        cin>>ch;
        if(ch=='+')
        {
            int pos,val;
            cin>>pos>>val;
            updatetree(1,1,n,pos,val);
        }
        if(ch=='?')
        {
            int ll,rr;
            cin>>ll>>rr;
            cout<<answerquery(1,1,n,ll,rr)<<endl;
        }
    }
}
signed main()
{
  cin.tie(0); cout.tie(0);
  solve();
}