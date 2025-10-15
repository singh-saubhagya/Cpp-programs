#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
int n,d;
vector<int> arr;
int t[400100];
const int inf=1e9;
vector<int> num;
void build(int id,int l,int r)
{
  if(l==r)
  {
    t[id]=0;
    return ;
  }
  int mid=l + ((r-l)>>1);
  build(id<<1,l,mid);
  build(id<<1|1,mid+1,r);
  t[id]=max(t[id<<1],t[id<<1|1]);
  return ;
}
void update(int id,int l,int r,int pn, int val)
{
  if(pn<l || pn > r)
  return ;
  if(l==r)
  {
    t[id]=max(t[id],val);
    return ;
  }
  int mid= l +((r-l)>>1);
  update(id<<1,l,mid,pn,val);
  update(id<<1|1,mid+1,r,pn,val);
  t[id]=max(t[id<<1],t[id<<1|1]);
  return ;
}
int answerquery(int id,int l,int r,int ll,int rr)
{
  if(l>rr || r<ll)
  return -inf;
  if(ll<=l && r<=rr)
  return t[id];
  int mid=l+((r-l)>>1);
  return max(answerquery(id<<1,l,mid,ll,rr),answerquery(id<<1|1,mid+1,r,ll,rr));
}
void solve()
{
  cin>>n;
  cin>>d;
  arr.resize(n+2);
  set<int> s;
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
    s.insert(arr[i]);
  }
  for(auto x: s)
  num.push_back(x);
  int nn=num.size();
  cout<<nn<<endl;
  build(1,0,nn-1);
  vector<int> dp;
  dp.resize(n+2);
  for(int i=0;i<n;i++)
  {
    int low=arr[i]-d;
    int high=arr[i]+d;
    int ll = lower_bound(num.begin(),num.end(),low)-num.begin();
    int rr = upper_bound(num.begin(),num.end(),high)-num.begin();
    int val=answerquery(1,0,nn-1,ll,rr);
    dp[i]=max(1,1+val);
    int pn=lower_bound(num.begin(),num.end(),arr[i])-num.begin();
    update(1,0,nn-1,pn,dp[i]);
  }
  int ans=-inf;
  for(int i=0;i<n;i++)
  {
    ans=max(ans,dp[i]);
  }
  cout<<ans<<endl;
}
signed main()
{
  cin.tie(0); cout.tie(0);
  solve();
}