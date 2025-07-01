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
#define f first
#define s second 
#define inf 1e9
vector<pair<lli,lli>> ng={{1,0},{-1,0},{0,-1},{0,1}};
int shortestPath(vector<vector<int>>& g, int k) {
 lli n=g.size();
 lli m=g[0].size();
 vector<vector<vector<lli>>> dist;
 dist=vector<vector<vector<lli>>>(n+1,vector<vector<lli>>(m+1,vector<lli>(k+1,inf)));
 queue<pair<pair<lli,lli>,lli>> q;
 pair<pair<lli,lli>,lli> st,en;
 st={{0,0},0};
 en={{n-1,m-1},0};
 q.push(st);
 dist[st.f.f][st.f.s][st.s]=0;
 while(q.empty()==false)
 {
  pair<pair<lli,lli>,lli> temp=q.front();
  q.pop();
  for(auto x:ng)
  {
    lli row,col;
    row=temp.f.f + x.f;
    col=temp.f.s + x.s;
    if(row>=0 && row < n && col>=0 && col<m)
    {
      lli wall=temp.s;
      if(g[row][col]==1)
      {
        wall++;
      }
      if(wall<=k)
      {
        lli dt=dist[temp.f.f][temp.f.s][temp.s] +1;
        if(dt<dist[row][col][wall])
        {
          dist[row][col][wall]=dt;
          q.push({{row,col},wall});
        }
      }
    }
  }
 }
 lli ans=LLONG_MAX;
 for(lli i=0;i<=k;i++)
 {
  ans=min(ans,dist[en.f.f][en.f.s][i]);
  
 }
  if(ans==inf)
  {
    return -1;

  }
  return ans;
}
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  int k=4;
        std::vector<std::vector<int>> data = {
            {0,0}, {1,0}, {1,0}, {1,0}, {1,0}, {1,0}, {0,0}, {0,1}, 
            {0,1}, {0,1}, {0,0}, {1,0}, {1,0}, {0,0}
        };
        cout<<shortestPath(data,k);
}