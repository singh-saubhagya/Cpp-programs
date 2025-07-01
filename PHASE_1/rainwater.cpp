
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
    vector<lli> arr;
    for(lli i=0;i<n;i++)
    {
        lli x;
        cin>>x;
        arr.push_back(x);
    }
    stack<lli> s;
    vector<lli>id1(n,0);// stores the index of the no which is greater than the no from lhs 
    vector<lli> id2(n,0);// stores the index of the no which is greater than the no from rhs
    s.push(0);
    id1[0]=(-1);
    for(lli i=1;i<n;i++)
    {
        if(arr[i]<arr[i-1])
        {
            id1[i]=(i-1);
            
        }
        else
        {
            // bool flag=true;
            while(s.empty()!=true && arr[s.top()]<=arr[i])
            {
                // if(arr[i]==arr[s.top()])
                // {
                //     if(id1[s.top()]!=-1)
                //     {
                //         id1[i]=i;
                //     }
                //     else
                //     {
                //         id1[i]=-1;
                //     }
                //      flag=false;
                     
                //     break;
                // }
                
                s.pop();
            }
            if(s.empty()==true)
            {
                id1[i]=-1;
            }
            else
            {
                // if(flag)
                id1[i]=s.top();
            }
        }
        s.push(i);
        
    }
   
    stack<lli> s1;
    s1.push(n-1);
    id2[n-1]=n;
    for(lli i=n-2;i>=0;i--)
    {
        if(arr[i]<arr[i+1])
        {
           id2[i]=i+1;
            
        }
        else if(arr[i]==arr[i+1])
        {
            if(id2[i+1]!=n)
            {
                id2[i]=id2[i+1];
            }
            else
            {
                id2[i]=n;
            }

        }
        else
        {
            bool flag=true;
            while(s1.empty()!=true && arr[s1.top()]<arr[i])
            {
                // if(arr[i]==arr[s1.top()])
                // {
                //     if(id2[s1.top()]!=n)
                //     {
                //         id2[i]=i;
                //     }
                //     else
                //     {
                //         id2[i]=n;
                //     }
                //     flag=false;
                //     break;
                // }
                
                s1.pop();
            }
            if(s1.empty()==true)
            {
                id2[i]=n;
            }
            else
            {
                if(flag)
                id2[i]=s1.top();
            }
        }
        s1.push(i);
    
    }
   
    lli cal=0;
   
    for(lli i=1;i<n-1;i++)
    {
        if(id1[i]!=-1 && id2[i]!=n)
        {
        if(arr[i]!=arr[i-1])
        {
        lli ht=abs(min(arr[id1[i]],arr[id2[i]])-arr[i]);
        lli wd=abs(id2[i]-id1[i])-1;
        cal+=ht*wd;
       
        }
        }
    }
    cout<<cal<<endl;
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