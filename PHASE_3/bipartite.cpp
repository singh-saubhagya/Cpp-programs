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


// appraoch 1 , check visited nighbour is colored differently , if not then it is not bipartite
// approach 2 , if odd cycles then not bipartite
vector<vector<lli>> g;
vector<lli> cs;
vector<lli> vis;
lli flag=1;
void dfs(lli node){
    if(flag==0)
    return;


    vis[node]=1;
    for(auto x:g[node]){
        
        if(vis[x]==0)
        {
          cs[x]=cs[node]%2+1;// coloring the neighbour
          dfs(x);
        }
        else
        {
            if(cs[x]==cs[node])// visited neighbour colored same therefore not bipartite
            {
               
                flag=0;
                break;
            }
        }

    }
    return ;
}
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  lli n,m;
  cin>>n>>m;
  g.resize(n+1);
  cs.resize(n+1,0);
  for(lli i=0;i<m;i++){
    lli a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vis.resize(n+1);
  for(lli i=1;i<=n;i++){
    if(vis[i]==0)
    {
        cs[i]=1;
   
        dfs(i);
        if(flag==0)
        {
           
            break;
        }
    }
  }
  if(flag)
  cout<<"POSSIBlE";
  else
  cout<<"NOT POSSIBLE"<<endl;
}