#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
//---- Debugger ---- //
#define debarr(a,n) cout<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debmat(mat,row,col) cout<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
lli binpow(lli b,lli p,lli mod){lli ans=1;b%=mod;for(;p;p>>=1){if(p&1)ans=ans*b%mod;b=b*b%mod;}return ans;}
//----------------- //
#define inf 1e9
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  lli n,m;
  cin>>n>>m;
  vector<vector<pair<lli,lli>>> g;
  g.resize(n+1);
  vector<pair<pair<lli,lli>,lli>> edge;
  for(lli i=0;i<m;i++)
  {
    int a,b,c;
    cin>>a>>b>>c;
    g[a].push_back({b,c});
    g[b].push_back({a,c});
    edge.push_back({{a,b},c});
  }
  lli st;
  cin>>st;
  priority_queue<pair<lli,lli>> pq;
  pq.push({0,st});
  vector<bool> marked(n+1,false);
  vector<lli> dist(n+1,inf);
  dist[st]=0;
  while(pq.empty()==false)
  {
    pair<lli,lli> x=pq.top();
    pq.pop();
    if(marked[x.second])
    continue;
    marked[x.second]=true;
    for(auto z:g[x.second])
    {
      lli a=z.first;//node
      lli b=z.second;//weight
      lli dt=abs(x.first)+b;
      if(dt<dist[a])
      {
        dist[a]=dt;
        pq.push({-dt,a});
      }
    }

  }
    lli ans=LLONG_MIN;
    for(auto x:edge){
      lli a=x.first.first;
      lli b=x.first.second;
      lli wt=x.second;
      lli t=dist[a]+dist[b]+wt;
      ans=max(ans,t*5);
    }
    cout<<ans<<endl;
}