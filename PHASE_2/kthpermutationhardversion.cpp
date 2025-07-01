#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define  tab '\t'
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


// check the website solution also pasted in comments below .
lli n,k;
vector<lli> arr,temp;
map<lli,lli> m;
lli level=1;
vector<lli> fact(14,1);
vector<lli> ans;lli l;
vector<vector<lli>> sol;

/*
How lccm framework works here:
Level: to find the kth permutaion we need to fill every position, so no of postion equal to levels , and these we need to iterated
Choose: Iterate through all the no.
Check: Choose only those no , which are not used, how?? there frequency count is not 0 
Move: Fill the position with correct no and move to next state, 
      here we need to find the distinct solution so we are not backtracking if we need 
      to find the all the solution we will backtrack

*/
lli findfact(lli x)
{
    if(x==0)
    return 1;
    else
    return x*findfact(x-1);
}
void rec(){

    if(level>l){
        //base case
   
    return;

    }
    for(auto x:m)
    {
        if(x.second>0)
        {
        lli a=fact[l-level];
        if(a>=k)
        {
            ans.push_back(x.first);
            m[x.first]=0;level++;
            rec();
        }
        else
        {
            k=k-a;
            
        }  
   
        
       
    }


}
}
signed main(){
    for(lli i=1;i<=12;i++)
    {
        fact[i]=findfact(i);
    }
    cin>>n>>k;
    arr.resize(n);
    for(lli i=0;i<n;i++)
    arr[i]=i+1;
 // the maximum value of k is 1e9 and we know 13! is > 1e9 , so our desired permutaion will lie in the last 13 elemenst of array having size
 // greated than or equal to 13,
   if(n>=13)
   {
   lli t=13;
   auto it=arr.end();
   while(t--)
   {
    it--;
   } 
    temp.assign(it,arr.end());
   }
   else
   {
    temp.assign(arr.begin(),arr.end());
   }
   for(auto x:temp){
    m[x]=1;
   }
   l=m.size();
    rec();
    if(n>=13)
    {
        for(lli i=0;i<=n-1-13;i++)
        {
            cout<<arr[i]<<" ";
        }
        for(auto x:ans)
        {
            cout<<x<<" ";
        }  
    }
    else
    {
          for(auto x:ans)
        {
            cout<<x<<" ";
        }   
    }

}






/*

#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

void func(int k, vector<int> &arr)
{
    int n = (int)arr.size();
    k--;
    vector<int> ans;
    int fact = 1;
    for (int i = 1; i < n; i++)
    {
        fact = i * fact;
    }
    while (1)
    {
        ans.push_back(arr[k / fact]);
        arr.erase(arr.begin() + k / fact);
        if ((int)arr.size() == 0)
            break;
        k %= fact;
        fact /= (int)arr.size();
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
}

void solve()
{
    int n, k;
    cin >> n >> k;
    if (n <= 13)
    {
        vector<int> arr;
        for (int i = 1; i <= n; i++)
        {
            arr.push_back(i);
        }
        func(k, arr);
    }
    else
    {
        vector<int> arr;
        for (int i = 1; i < n - 12; i++)
        {
            cout << i << " ";
        }
        for (int i = n - 12; i <= n; i++)
        {
            arr.push_back(i);
        }
        func(k, arr);
    }
}

signed main()
{
    IOS;
    solve();
    return 0;
}

*/