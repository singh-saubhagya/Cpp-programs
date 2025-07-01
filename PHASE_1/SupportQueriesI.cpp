
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

struct blackhole
{
 multiset<lli> s;
 lli sum=0;
 void add()
 {
    lli x;
    cin>>x;
    s.insert(x);
    sum+=x;
 }
 void remove()
 {
    lli x;
    cin>>x;
    auto it=s.find(x);
    if(it!=s.end())
    {
        s.erase(it);
        sum-=x;
    }
 }
 void printmin()
 {
    if(s.size()==0)
    {
        cout<<-1<<endl;
        return;
    }
    auto it=s.begin();
    cout<<*it<<endl;
 }
 void printmax()
 {
    if(s.size()==0)
    {
        cout<<-1<<endl;
        return;
    }
    auto it=s.rbegin();
    cout<<*it<<endl;
 }
 void printsum()
 {
    if(s.size()==0)
    {
        cout<<0<<endl;
        return;
    }
    cout<<sum<<endl;
 }

};

signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  blackhole bh;
  lli q;
  cin>>q;
  while(q--)
  {
    lli x;
    cin>>x;
    if(x==1)
    {
        bh.add();
    }
    else if(x==2)
    {
        bh.remove();
    }
    else if(x==3)
    {
        char ch;
        cin>>ch;
        bh.printmin();
    }
    else if(x==4)
    {
        char ch;
        cin>>ch;
        bh.printmax();
    }
    else if(x==5)
    {
          char ch;
        cin>>ch;
        bh.printsum();
    }
  }

}