
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

struct setoperations{
vector<lli> s1,s2;
lli n,m;
void removeduplicate(vector<lli> &v,lli n)
{
    sort(v.begin(),v.end());
    lli l=0;
    for(auto it=v.begin()+1;it!=v.end();it++)
    {
        if(*it==v[l])
        {
            v.erase(it);
            it--;
            continue;
        }

    }
    
}
void initialize()
{
    cin>>n>>m;
    for(lli i=0;i<n;i++)
    {
        lli x;
        cin>>x;
        s1.push_back(x);
    }
    for(lli i=0;i<m;i++)
    {
        lli x;
        cin>>x;
        s2.push_back(x);
    }
    removeduplicate(s1,n);
    removeduplicate(s2,m);
}

void unionofsets()
{
    vector<lli> v;//union set
    lli p1,p2;
    p1=0;
    p2=0;
    while(p1!=n && p2!=m)
    {
        if(s1[p1]<s2[p2])
        {
            
           v.push_back(s1[p1]);
            p1++;
        }
        else if(s1[p1]>s2[p2])
        {
            v.push_back(s2[p2]);
            p2++;
        }
        else
        {
           
            v.push_back(s2[p2]);
            p1++;
            p2++;
        }

    }
    if(p1!=n)
    {
        while(p1!=n)
        {
            v.push_back(s1[p1]);
            p1++;
        }
    }
    else
    {
        while(p2!=m)
        {
            v.push_back(s2[p2]);
            p2++;
        }
    }
    for(lli x:v)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}
void findintersection()
{
    vector<lli> v;//union set
    lli p1,p2;
    p1=0;
    p2=0;
    while(p1!=n && p2!=m)
    {
        if(s1[p1]<s2[p2])
        {
            p1++;
        }
        else if(s1[p1]>s2[p2])
        {
            p2++;
        }
        else
        {
           
            v.push_back(s2[p2]);
            p1++;
            p2++;
        }

    }
    
    for(lli x:v)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}
void subtractionofsets()
{

    vector<lli> v;//union set
    lli p1,p2;
    p1=0;
    p2=0;
    while(p1!=n && p2!=m)
    {
        if(s1[p1]<s2[p2])
        {
            
           v.push_back(s1[p1]);
            p1++;
        }
        else if(s1[p1]>s2[p2])
        {
            p2++;
        }
        else
        {
            p1++;
            p2++;
        }

    }
    if(p1!=n)
    {
        while(p1!=n)
        {
            v.push_back(s1[p1]);
            p1++;
        }
    }
    
    for(lli x:v)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    
}
  void clearthearray()
  {
    s1.clear();
    s2.clear();
  }
};

signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  lli t;
  cin>>t;
  setoperations x;
  while(t--)
  {
 
  x.initialize();
  x.unionofsets();
  x.findintersection();
  x.subtractionofsets();
  x.clearthearray();
  
  }

}