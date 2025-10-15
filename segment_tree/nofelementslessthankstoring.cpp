#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
using pp=pair<int,int> ;
int t[400100];
void build(int id,int l,int r)
{
    if(l==r)
    {
        t[id]=0;
        return ;
    }
    int mid = l + ((r-l)>>1);
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    t[id]=t[id<<1]+t[id<<1|1];
    return ;
}
void update(int id,int l,int r, int pn)
{
    if(pn<l || pn>r)
    return ;
    if(l==r)
    {t[id]=1;
    return ;}

    int mid=l+((r-l)>>1);
    update(id<<1,l,mid,pn);
    update(id<<1|1,mid+1,r,pn);
    t[id]=t[id<<1]+t[id<<1|1];
    return ;
}
int answerquery(int id,int l,int r, int ll,int rr)
{
    if(l>rr || r<ll)
    return 0;
    
    if(l>=ll && r<=rr)
    return t[id];
    int mid=l+((r-l)>>1);
    return answerquery(id<<1,l,mid,ll,rr)+answerquery(id<<1|1,mid+1,r,ll,rr);

}
void solve()
{
  int n;
  cin>>n;
  vector<int> arr;
  arr.resize(n);
  multimap<int,int> cord;
  for(int i=0;i<n;i++)
  {
   cin>>arr[i];
   cord.insert({arr[i],0});
  }
  int cnt=0;
  vector<int> rev;
  for(auto &x: cord)
  {
    x.second=cnt++;
    rev.push_back(x.first);
  }
  int nn=rev.size();
  build(1,0,n-1);
  int q;
  cin>>q;
  
  vector<pair<pp,pp>> que;
  for(int i=0;i<q;i++)
  {
    int ll,rr,k;
    cin>>ll>>rr>>k;
    pp a={k,i};
    pp b={ll,rr};
    pair<pp,pp> x={a,b};
    que.push_back(x);
    
  }
  sort(que.begin(),que.end());
  sort(arr.begin(),arr.end());
  int pos=0;
  vector<int> fa;
  fa.resize(q+2);
  for(auto x: que)
  {
    int k=x.first.first;
    int pn=x.first.second;
    int ll=x.second.first;
    int rr=x.second.second;
    while(pos<n && arr[pos]<=k)
    {
        
        update(1,0,nn-1,pos);
        pos++;
    }
    int ans=answerquery(1,0,n-1,ll,rr);
    fa[pn]=ans;
   
  }
  
  for(int i=0;i<q;i++)
  {
    cout<<fa[i]<<endl;
  }
}
signed main()
{
  cin.tie(0); cout.tie(0);
  solve();
}