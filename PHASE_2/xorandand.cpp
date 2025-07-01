
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
vector<lli> arr;
const lli m=1e9+7;

// if we are asked to take modulo and we are calculating the large power raise to 2, they will give wrong answer , in this situation one should use binpow
void enigma(){
    lli n;
    cin>>n;
    arr.resize(n);
    for(lli i=0;i<n;i++){
        cin>>arr[i];
    }
    lli sumxor=0;
    lli sumand=0;
    lli sumxorsub=0;
    lli sumandsub=0;

    for(lli i=0;i<63;i++){
        
        lli stbit=0;
        for(lli j=0;j<n;j++){
            //calculating the no of one on the ith bit in the array
            if((1LL<<i)&arr[j]){
                stbit++;
            }
        } 
        if(stbit>0)
        {
        // handle the case when no of set bits is only 1
        lli utbit=n-stbit;
        lli ppxor=stbit*utbit;
        lli ppand=stbit*(stbit-1)/2;
        lli ssand=(binpow(2,stbit,m))-1;
       
       
       
        sumxor=(sumxor%m+(ppxor%m*(binpow(2,i,m)))%m)%m;
        sumand=(sumand%m+(ppand%m*(binpow(2,i,m)))%m)%m;
        sumandsub=(sumandsub%m+(ssand%m*(binpow(2,i,m))%m)%m)%m;
        sumxorsub=(sumxorsub%m+((binpow(2,n-1,m))*(binpow(2,i,m)))%m)%m; 
        }
    }
    cout<<sumxor<<" "<<sumxorsub<<" "<<sumand<<" "<<sumandsub<<endl;
}
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  lli t;
  cin>>t;
  while(t--)
  enigma();

}