
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


void solving_query()
{
    lli q;
    cin>>q;
    set<lli> s;
    while(q--)
    {
        string str;
        cin>>str;
        if(str=="add")
        {
            lli x;
            cin>>x;
            if(s.find(x)==s.end())
            {   
                s.insert(x);
            }
        }
        else if(str=="remove")
        {
            lli x;
            cin>>x;
            if(!s.empty())
            {
             if(s.find(x)!=s.end())
               {   
                s.erase(x);
               }
            }
            

        }
        else if(str=="find")
        {
            lli x;
            cin>>x;
            if(!s.empty())
            {
                    if(x>=0 && x<=s.size()-1)
                    {
                        auto it=s.begin();
                        while(x--)
                        {
                            it++;
                        }
                        cout<<*it<<endl;
                    }
                    else
                    cout<<-1<<endl;
                
            }
            else
            cout<<"-1"<<endl;
           

        }
        else if(str=="findpos")
        {
            lli x;
            cin>>x;
            if(!s.empty())
            {
                    if(s.find(x)!=s.end())
                    {
                        auto it=s.find(x);
                        lli l=distance(s.begin(),it);
                        cout<<l<<endl;
                    }
                    else
                    {
                        auto it=s.upper_bound(x);
                        lli l=distance(s.begin(),it);
                        cout<<l<<endl;
                    }
            }
            else
            {
                cout<<"0"<<endl;
            }
            
        }
    }
}
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  lli t;
  cin>>t;
  while(t--)
  {
    solving_query();
  }

}