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




lli n;
lli k;
vector<vector<pair<lli,lli>>> allsol;
vector<pair<lli,lli>> ans;
lli level=0;

lli prevcol;
bool canplace(lli i,lli j){

for(auto x:ans)
{

    if(x.first==i || x.second==j || abs(i-x.first)==abs(j-x.second))
    {
        return 0;
    }
}
return 1;
}
lli ct=0;
bool prevqueen(lli i,lli j){
    if(ans.empty()==true)
    return 1;
    auto it=ans.back();
    if(i>it.first)
    return 1;
    return 0;
}
void rec(){

    if(level==k){
        allsol.push_back(ans);
        // pr(ans);
        ct++;
        return;
    }
    for(lli i=0;i<n;i++){
        for(lli j=0;j<n;j++){
            if(canplace(i,j)&& prevqueen(i,j)){
                
                
                // pr(i);
                // pr(j);
                // pr(ans);
                level++;
                ans.push_back({i,j});
                rec();
                level--;
                ans.pop_back();
                
            }

        }
    }
    return;
}
signed main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  
cin>>n>>k;
rec();
pr(ct);
// for(auto x:allsol)
// {
   
//     pr(x);
// }

}
