#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

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

// in this question , we will use two pointer approach , for each tail the most optimum head will be when no of odd k elements <k
// now we subarray with sum < d will be any subarray from this tail to head range , which we can find using 
// p[r]-p[l-1]<=d => p[r]-d=p[l-1], here r is all the heads in the range tail to maximum head for given tail
// so the possible value of l are tail -1 to  head -1, which we are going to maintain in the multiset s
vector<lli> arr;
vector<lli> ps;//prefix sum 
map<lli,lli> m;
void enigma(){

  lli n,k,d;
  cin>>n>>k>>d;
  arr.resize(n+1);
  ps.resize(n+1,0); 
  for(lli i=1;i<=n;i++)
  {
    cin>>arr[i];
    ps[i]=arr[i]+ps[i-1];
  }

  lli tail=1;
  lli head=0;
  lli ct=0;
  lli ans=LLONG_MIN;
  // pr(ps);  
  multiset<lli> s;
  while(tail<=n)
  {
    
    while(head+1<=n && ( ct<k || abs(arr[head+1])%2==0 ))
    {
      s.insert(ps[head]);// for the give head+1 value , the prefix sum values in the set s are , tail -1 to head -1, so as we are incrementing head by 1 we have to add ps[head] in the set.
      head++;
      if(abs(arr[head])&1)
      {
        ct++;
      }
      lli l=ps[head]-d;
      auto it=s.lower_bound(l);
      if(it!=s.end())
      {
        ans=max(ans,ps[head]-*it);
      }
    }
    
    if(s.find(ps[tail-1])!=s.end())// now we are incrementing tail sand  we don't want ps[tail-1], in the set thus deleting ps[tail-1]  if present.
    {
      s.erase(s.find(ps[tail-1]));
    }
    // pr(head);
    // pr(tail);
    // pr(s);
    if(tail>head)
    {
      tail++;
      head=tail-1;
    }
    else
    {
      if(abs(arr[tail])&1)
      {
        ct--;
      }
      tail++;
    }
  }
  if(ans==LLONG_MIN)
  {
    cout<<"IMPOSSIBLE"<<endl;
  }
  else{
    cout<<ans<<endl;
  }
}
signed main()
{
  lli t;
  cin>>t;
  while(t--)
  enigma();
  
  
}