#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define tab '\t'
#define endl '\n'



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



void solve()
{
    lli n;
    cin>>n;
    vector<lli> a,b;
    for(lli i=0;i<n;i++)
    {
        lli x;
        cin>>x;
        a.push_back(x);
    }
    for(lli i=0;i<n;i++)
    {
        lli x;
        cin>>x;
        b.push_back(x);
    }
    multimap<lli,pair<lli,lli>> m;
    for(lli i=0;i<n;i++)
    {
        lli temp=a[i]+b[i];
        m.insert({temp, {a[i], b[i]}});    // sorting with respect to the sum of a[i]+b[i]
        // why a[i]+b[i]?
        // Seeing from the perspective of a at the end of game we want sa-sb to be maximum for a consistent and efficient algorithm
        /*Let we have intially no of cards with A as zero and B has all n cards so the sa=0 and sb=sigma(bi)
        and sa-sb=-signum(bi) and now we transfer one card from b to a , then resultant score will be 
        sa=aj and sb=signum(bi)-bj and now sa-sb=aj-(signum(bi)-bj) and now delta(sa-sb)=aj+bj */
    }
    lli turn =1;
    lli sa=0,sb=0;
    for(auto it=m.rbegin();it!=m.rend();it++)
    {
        if(turn)
        {
            sa=(it->second).first+sa;
            turn=0;
        }
        else
        {
            sb=(it->second).second+sb;
            turn=1;
        }
    }
    if(sa>sb)
    {
        cout<<"Alice"<<endl;
    }
    else if(sa<sb)
    {
        cout<<"Bob"<<endl;
    }
    else
    {
        cout<<"Tie"<<endl;
    }
}
int main()
{
    lli t;
    cin>>t;
    while(t--)
    {
        solve();

    }
}