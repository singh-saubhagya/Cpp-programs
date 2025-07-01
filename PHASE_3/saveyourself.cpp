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
lli n,m;
vector<vector<lli>> avis;
vector<vector<lli>> mvis;
vector<vector<char>>g;
vector<pair<lli,lli>> ng={{1,0},{-1,0},{0,1},{0,-1}};
void bfsa(pair<lli,lli> node)
{
    queue<pair<lli,lli>> q;
    q.push(node);
    avis[node.first][node.second]=0;
    while(q.empty()==false){
        pair<lli,lli> x;
        x=q.front();
        q.pop();
        for(auto z:ng)
        {
            lli row,col;
            row=z.first+x.first;
            col=z.second+x.second;
            
            if((row>=0 && row <n && col>=0 && col<m) &&  g[row][col]!='#' && avis[row][col]==inf)
            {
                avis[row][col]=avis[x.first][x.second]+1;
                q.push({row,col});
            }
        }
    }

}
vector<pair<lli,lli>> mst;//monster
void bfsm(){
   
    queue<pair<lli,lli>> q;
  
    for(lli i=0;i<mst.size();i++)
    {
        
    q.push(mst[i]);
    mvis[mst[i].first][mst[i].second]=0;
  
    }
    while(q.empty()==false){
        pair<lli,lli> x;
        x=q.front();
        q.pop();
        for(auto z:ng)
        {
            lli row,col;
            row=z.first+x.first;
            col=z.second+x.second;
            
            if((row>=0 && row <n && col>=0 && col<m) &&  g[row][col]!='#' && mvis[row][col]==inf)
            {
                mvis[row][col]=mvis[x.first][x.second]+1;
                q.push({row,col});
            }
        }
    }  
}
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  pair<lli,lli> st;//starting point
 



  cin>>n>>m;
  avis=vector<vector<lli>>(n,vector<lli>(m,inf));
  mvis=vector<vector<lli>>(n,vector<lli>(m,inf));

  
  g.resize(n);
  for(lli i=0;i<n;i++)
  {
    g[i].resize(m);
    for(lli j=0;j<m;j++)
    {
        char ch;
        cin>>ch;
        g[i][j]=ch;
        if(ch=='A')
        {
            st={i,j};
        }
        else if (ch=='M')
        {
            mst.push_back({i,j});
         
        }
    }
  }
    bfsa(st);// bfs for staring point 
    bfsm();
  
    lli ans=LLONG_MAX;
    bool flag=false;
    for(lli i=0;i<n;i++)
    {
        for(lli j=0;j<m;j++)
        {
            if(i==0 || j==0 || i==n-1 || j==m-1)
            {

                if(avis[i][j]<mvis[i][j])
                {
                    ans=min(ans,avis[i][j]);
                    flag=true;

                }
            }
        }
    }
    if(flag)
    {
        cout<<"YES"<<endl;
        cout<<ans<<endl;
    }
    else
    cout<<"NO"<<endl;
}