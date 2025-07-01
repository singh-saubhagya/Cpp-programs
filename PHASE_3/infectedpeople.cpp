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
vector<pair<lli,lli>> ng={{1,0},{-1,0},{0,1},{0,-1}};
int  main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  lli n,m;
  cin>>n>>m;
  vector<vector<lli>> g;
  g.resize(n);
  vector<pair<lli,lli>> z;
  lli ans=0;
  for(lli i=0;i<n;i++)
  {
    g[i].resize(m);
    for(lli j=0;j<m;j++)
    {
        int x;
        cin>>x;
        g[i][j]=x;
        if(x==2)
        {
            z.push_back({i,j});
        }
    }
  }
  vector<vector<lli>> vis;
  vis.resize(n,vector<lli>(m,-1));
  queue<pair<lli,lli>> q;
  for(auto y:z)
  {
    q.push(y);
    vis[y.first][y.second]=0;
  }
  while(q.empty()==false)
  {
    pair<lli,lli> x=q.front();
    q.pop();
    for(auto y:ng)
    {
        lli row,col;
        row=y.first+x.first;
        col=y.second+x.second;
        lli dt=vis[x.first][x.second]+1;
        if((row>=0 && row <n && col>=0 && col<m ) && g[row][col]==1 &&  (vis[row][col]==-1 ) )
        {
            
            vis[row][col]=dt;
            q.push({row,col});
        }
    }
  }
  for(lli i=0;i<n;i++)
  {
    for(lli j=0;j<m;j++)
    {
        if(g[i][j]==1)
        {
            if(vis[i][j]==-1)
            {
                cout<<-1<<endl;
                return 0;
            }
            ans=max(ans,vis[i][j]);

        }
    }
  }

    cout<<ans<<endl;
   return 0;

}