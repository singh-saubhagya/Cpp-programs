
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


void enigma()
{
    lli n;
    cin>>n;
    vector<lli> arr,id1;
    stack<lli> s;
    vector<lli> id2(n,0);
    for(lli i=0;i<n;i++)
    {
        lli x;
        cin>>x;
        arr.push_back(x);
    }
    s.push(0);
    id1.push_back(-1);
    for(lli i=1;i<n;i++)
    {
        if(arr[i]>arr[i-1])
        {
            id1.push_back(i-1);
            
        }
        else
        {
            while(s.empty()!=true && arr[s.top()]>=arr[i])
            {
                s.pop();
            }
            if(s.empty()==true)
            {
                id1.push_back(-1);
            }
            else
            {
                id1.push_back(s.top());
            }
        }
        s.push(i);
    }
    
    stack<lli> s1;
    s1.push(n-1);
    id2[n-1]=n;
    for(lli i=n-2;i>=0;i--)
    {
        if(arr[i]>arr[i+1])
        {
           id2[i]=i+1;
            
        }
        else
        {
            while(s1.empty()!=true && arr[s1.top()]>=arr[i])
            {
                s1.pop();
            }
            if(s1.empty()==true)
            {
                id2[i]=n;
            }
            else
            {
                id2[i]=s1.top();
            }
        }
        s1.push(i);
    }

    
    lli maxx=INT_MIN;
    for(lli i=0;i<n;i++)
    {
        lli temp=abs(id2[i]-id1[i]);
        lli cal=(temp-1)*arr[i];
        if(cal>maxx)
        {
            maxx=cal;
        }
    }
    cout<<maxx<<endl;
}
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  lli t;
  cin>>t;
  while(t--)
  {
    enigma();
  }

}