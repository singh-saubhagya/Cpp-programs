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
string str;
lli level=0;
set<pair<lli,char>> pn;
lli ct=0;
map<char, pair<lli, lli>> mov = {
    {'L', {0, -1}},
    {'R', {0, 1}},
    {'U', {-1, 0}},
    {'D', {1, 0}}
};
vector<pair<lli,lli>> ans;
bool valid(char ch,pair<lli,lli> x)
{
  if(x.first<0 || x.first>6 || x.second>6 || x.second<0 )
  return false;
  for(auto z: ans)
  {
    if(z.first==x.first && z.second==x.second)
    {
      return false;
    }
  }
  return true;

  
}
void rec(lli i,lli j)
{
  
  if(i==6 && j==0 && level!=48)
  {
    return;
  }
  if(level==48 && i==6 && j==0)
  {
    ct++;
    return;
  } 
  if(level>=48 )
  return;


  auto a=pn.begin();
  if(a!=pn.end())
  {pair<lli,lli> b=*a;
    if(b.first==level+1)
  {
    char ch=b.second;
    
    lli m=mov[ch].first;
    lli n=mov[ch].second;
    pn.erase(a);
    rec(m,n);
    return;
  }}
  for(auto x:mov){ 
      lli m=x.second.first+ i;
      lli n=x.second.second + j;
    if(valid(x.first,{m,n}))
    {
     
      level++;
      ans.push_back({m,n});
      rec(m,n);
      level--;
      ans.pop_back();

    }
  }
}
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
 
  cin>>str;
  
  for(lli i=0;i<str.length();i++)
  {if(str[i]!='?')
    {
      pn.insert({i+1,str[i]});
    }
  }
 
  ans.push_back({0,0});
  rec(0,0);
  cout<<ct<<endl;
}