#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
vector<int> arr;
int t[400007];
void addnumber(int id,int l,int r,int x)
{
    int mid=l+(r-l)/2;
    if(l==r)
    {
        t[id]=1;
        return ;
    }
    if(x<=mid)
    {
        addnumber(id<<1,l,mid,x);
      
    }
    else 
    {
        addnumber(id<<1|1,mid+1,r,x);
    }
    t[id]=t[id<<1]+t[id<<1|1];
    return ;
}
 void removenumber (int id,int l,int r,int x)
 {
    int mid=l+(r-l)/2;
    if(l==r)
    {
        t[id]=0;
        return ;
    }
    if(x<=mid)
    {
        removenumber(id<<1,l,mid,x);
    }
    else 
    {
        removenumber(id<<1|1,mid+1,r,x);
    }
    t[id]=t[id<<1]+t[id<<1|1];
    return ; 
 }
int answerquery(int id,int l,int r,int k)
{
    int mid=l+(r-l)/2;
    if(l==r)
    return l;
    if(t[id<<1|1]>=k)
    {
        return answerquery(id<<1|1,mid+1,r,k);
    }
    else 
    {
        return answerquery(id<<1,l,mid,k-t[id<<1|1]);
    }

}
void solve()
{
    int n;
    cin>>n;
    vector<int> height;
    height.resize(n+2);
    for(int i=1;i<=n;i++)
    cin>>height[i];

    arr.resize(n+2);
    memset(t,0,sizeof(t));
    for(int i=1;i<=n;i++)
    cin>>arr[i];

    for(int i=1;i<=n;i++)
    {
        addnumber(1,0,100000,height[i]);
    }
    vector<int> res;
    res.resize(n+2);
    for(int i=n;i>=1;i--)
    {
        int val=arr[i]+1;
        int ans=answerquery(1,0,100000,val);
        res[i]=ans;
        removenumber(1,0,100000,ans);
    }
    for(int i=1;i<=n;i++)
    cout<<res[i]<<" ";
}
signed main()
{
  cin.tie(0); cout.tie(0);
  solve();
}