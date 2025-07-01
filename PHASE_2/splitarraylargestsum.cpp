
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
vector<lli> arr={7,2,5,10,8};
lli n=5,k=2;
bool check(lli mid)
{
    int sum=0;
    lli count=1;
    int size=arr.size();
    for(int i=0;i<size;i++)
    {
        sum=sum+arr[i];
        if(arr[i]>mid)
        {
            return false;
        }
        if( sum>mid)// to check whether alloted time don't exceeed the mid amount and if so then decrease the no of painter and start its time from sum =0!
        {
            sum=arr[i];
            count++;
           
        }

        

    }
    cout<<"mid"<<tab<<mid<<tab<<"count"<<tab<<count<<endl;
    if(count<=k) 
    return true;
    else 
    return false;
    
}
void enigma()
{
    lli sum=0;
    lli minimum=LLONG_MIN;
    for(lli i=0;i<n;i++)
    {
        sum+=arr[i];
        if(arr[i]>minimum)
        {
            minimum=arr[i];
        }

    }
    lli lo=minimum;
    lli hi=sum;
    lli ans;
    while(lo<=hi)
    {
        lli mid=lo+(hi-lo)/2;
        cout<<"lo"<<tab<<lo<<tab<<"hi"<<tab<<hi<<endl;
        if(check(mid))
        {
            ans=mid;
            hi=mid-1;
        }
        else
        {
             lo=mid+1; 
        }
    }
    cout<<ans<<endl;
}
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  enigma();
 
}