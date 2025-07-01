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
vector<pair<lli,lli>> ng={{1,0},{-1,0},{0,-1},{0,1}};
#define inf 1e9
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  lli n,m;
  cin>>n>>m;
  vector<vector<char>> g;
  g.resize(n+1);
  for(lli i=1;i<=n;i++)
  {
    g[i].resize(m+1);
    for(lli j=1;j<=m;j++)
    {
        char ch;
        cin>>ch;
        g[i][j]=ch;
      
    }
  }
  vector<vector<bool>> marked;
  marked.resize(n+1,vector<bool>(m+1,false));
  vector<vector<lli>> dist;
  dist.resize(n+1,vector<lli>(m+1,inf));
  deque<pair<lli,pair<lli,lli>>> dq;
  dq.push_front({0,{1,1}});
  dist[1][1]=0;
  while(dq.empty()==false)
  {
    auto x=dq.front();
    dq.pop_front();
    lli a=x.second.first;// row no 
    lli b=x.second.second;// col no 
    lli c=x.first;// distance from 1,1
    if(marked[a][b])
    continue;
    marked[a][b]=true;
    for(auto z:ng)
    {
        lli row=a+z.first;
        lli col=b+z.second;
      
        
        if((row>=1 && row<=n && col>=1 && col<=m) )
        {   lli cost;
       //  
            if(row-a==1)// moved right
            {
             
              if(g[a][b]=='3')
              {
                cost=0;
              }
              else
              {
                cost=1;
              }
            }
            else if (row-a==-1)// moved left
            {
               
                if(g[a][b]=='4')
                {
                  cost=0;
                }
                else
                {
                  cost=1;
                }
            }
            else if (col-b==1)// moved downward
            {
                
                if(g[a][b]=='1')
                {
                  cost=0;
                }
                else
                {
                  cost=1;
                }
                
            }
            else if (col-b==-1)// moved upward
            {
              
                if(g[a][b]=='2')
                {
                  cost=0;
                }
                else
                {
                  cost=1;
                }
            }
            lli dt=cost+c;
            if(dt<dist[row][col])
            {
                dist[row][col]=dt;
                if(cost==0)
                {
                    dq.push_front({dt,{row,col}});
                }
                else
                {
                    dq.push_back({dt,{row,col}});
                }
            }
           
        }
    }
  }
  cout<<dist[n][m]<<endl;

}