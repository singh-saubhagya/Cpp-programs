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
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  lli n,m;cin>>n>>m;
  vector<vector<char>> g;
  vector<vector<lli>> dist(n,vector<lli>(m,inf));
  vector<vector<bool>> marked(n,vector<bool>(m,false));
  g.resize(n);
  pair<lli,lli> st,en;
  for(lli i=0;i<n;i++){
    g[i].resize(m);
    for(lli j=0;j<m;j++)
    {
        char ch;
        cin>>ch;
        g[i][j]=ch;
        if(ch=='S')
        {
            st={i,j};
        }
        if(ch=='E')
        {
            en={i,j};
        }
    }
  }
  priority_queue<pair<lli,pair<lli,lli>>> pq;
  pq.push({0,st});
  dist[st.first][st.second]=0;
  while(pq.empty()==false){
    auto x=pq.top().second;// node 
    lli q=abs(pq.top().first);// no of wall broken till now 
    pq.pop();
    if(marked[x.first][x.second])
    continue;
    marked[x.first][x.second]=true;
    for(auto y:ng)
    {
        lli row=y.first + x.first;
        lli col=y.second + x.second;
        if(row>=0 && row <n && col >=0 && col < m )
        {
            lli dt=q;
            if(g[row][col]=='#')
            {
                 dt++;
            }
            if(dt<dist[row][col])
            {
                dist[row][col]=dt;
                pq.push({-dt,{row,col}});
            }
        }
    }
  }
//   for(lli i=0;i<n;i++)
//   {
//     for(lli j=0;j<m;j++)
//     {
//         cout<<dist[i][j]<<" ";
//     }
//     cout<<endl;
//   }
  cout<<dist[en.first][en.second]<<endl;
}