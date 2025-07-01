
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
lli n;


// condition to check where to use two pointer !!!!
// if for some l there is a an optimal r then for l+1 the constrain must hold true for l+1 to atleast r 

void enigma()
{
    lli head,tail;
    head=-1;
    tail=0;
    lli ans;
    lli constraint;
    while(tail <n)
    {
        while(head+1<n)  /*one more condn described below*/

        /*condition to check the current tail is valid to maximum optimal head so basicall we will write if
        for current head the constrain is valid or not and the next head is should be considered or not*/
        {
            head++;
            // change the state of condition
            // will update the constrain based on the quesition
        }
        // now we will get a optimal head or current tail
        // store in ans variable
        if(tail>head)
        {// this if condition is used to handle the sitution when there is no optimal head for current tail so , the size is 0 of the window
            tail++;
            head=tail-1;
        }
        else
        {
            // now tail will change so change the constraint based on the current tail value 
            // changed the constaint 
            tail++;
            // change the constrain based on the updated tail value
        }
    }
}

signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  

}