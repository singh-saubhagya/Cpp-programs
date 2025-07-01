
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

void ans_to_query(){
    lli q,k;
    cin>>q>>k;
    multiset<lli> s;
    lli length=0;
    lli sum=0;
    auto it=s.begin();
    while(q--)
    {
        lli x;
        cin>>x;
        if(x==1)
        {
            lli temp;
            cin>>temp;
            temp=temp*-1;
            if(length==0)// first element
            {
                s.insert(temp);
                it=s.begin();
                sum+=temp;
                length++;
            }
            else{
                if(temp<*it) // lhs of kth element
                {
                    s.insert(temp);
                    length++;
                    if(length<=k)// less than or equal to k
                    {
                        // no problem
                        
                    }
                    else// size greater than k
                    {
                        sum-=*it;
                        it--;
                        
                    }

                    sum+=temp;
                }
                else// rhs of kth element
                {
                    if(length<k)
                    {
                        s.insert(temp);
                        it++;
                        sum+=temp;
                    }
                    else
                    {
                        s.insert(temp);
                    }
                    length++;
                }
            }
            
            
            
        }
        else if(x==2)
        {
            lli temp;
            cin>>temp;
            temp=temp*-1;
            if(s.find(temp)!=s.end())
            {
                auto z=s.find(temp);
                if(length<=k)// length less than or equal to k
                {
                    sum-=temp;
                    if(z==it)// kth element to be deleted 
                    {
                        it--;
                        s.erase(z);
                    }
                    else
                    {
                        s.erase(z);
                    }
                }
                else{// length greater than k
                    if(*z>*it)// on the rhs of kth element
                    {
                        s.erase(z);
                    }
                    else// on the lhs of kth element
                    {
                        
                        it++;
                        s.erase(z);  
                        sum-=temp;
                        sum+=*it;
                    }
                }
                length--;
                
            }
        }
        else if(x==3) 
        {
            char ch;
            cin>>ch;
            if(ch=='?')
            { 
                if(!s.empty())
                {
                    cout<<sum*-1<<endl;
                }
                else
                {
                    cout<<0<<endl;
                }
            }

        }
    }
}
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  ans_to_query();

}