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
#define f first
#define s second
vector<pair<lli,lli>> ng={{1,0},{-1,0},{0,1},{0,-1}};
vector<vector<pair<lli,lli>>> root;

signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  lli n,m;
  cin>>n>>m;
  vector<string> g;
  g.resize(n);
  vector<pair<lli,lli>> st,en;

  for(lli i=0;i<n;i++)
  {
    cin>>g[i];
    for(lli j=0;j<m;j++)
    {
        if(g[i][j]=='S')
        {
            st.push_back({i,j});
        }
        if(g[i][j]=='F')
        {
            en.push_back({i,j});
        }
    }
  }
  vector<vector<lli>> dist(n,vector<lli>(m,inf));
  queue<pair<lli,lli>> q;
  root=vector<vector<pair<lli,lli>>>(n,vector<pair<lli,lli>>(m));
  for(auto x:en)
  {
      dist[x.f][x.s]=0;
      root[x.f][x.s]={x.f,x.s};
      q.push({x.f,x.s});
  }
  while(q.empty()==false)
  {
    auto x=q.front();
    q.pop();
    for(auto z:ng)
    {
        lli row=z.f+x.f;
        lli col=z.s+x.s;
        if(row>=0 && row<n && col>=0 && col<m)
        {
            if(dist[row][col]==inf)
            {
                dist[row][col]=dist[x.f][x.s]+1;
                root[row][col]=root[x.f][x.s];
                q.push({row,col});
            }
        }
    }
  }
  for(auto x:st)
  {
    cout<<dist[x.f][x.s]<<" "<<root[x.f][x.s]<<endl;// to find the closed distance between any f to any s , find the minimum among all the distance of s
  }


}