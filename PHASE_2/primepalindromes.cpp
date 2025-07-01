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
lli binpow(lli b,lli p){lli ans=1;b;for(;p;p>>=1){if(p&1)ans=ans*b;b=b*b;}return ans;}
//----------------- //

lli a,b;
lli num=0;
lli temp;
lli noofdg(lli a){
    lli ct=0;
    while(a!=0){
        ct++;
        a/=10;    
    }
    return ct++;
}
lli ct=0;
lli p;
lli level=1;
bool ckprime(lli n)
{
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i <= std::sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;

}
bool valid(lli c)
{
    if(c>=a && c<=b  && ckprime(c))
    return true;
    return false;
}
void rec(lli n,lli m){
    
        if(level>m)
        {
            if(valid(num))
        ct++;//   {    cout<<num<<endl;}
            return;
        }
   

    for(lli i=0;i<=9;i++){
        if(level==1 && i==0)
        continue;
        if(level==m && n&1)
        {
        num+=i*binpow(10,n-level);  
        level++;
        rec(n,m);
        level--;
        num-=i*binpow(10,n-level);
        }
        else 
       { num+=i*binpow(10,n-level)+i*binpow(10,level-1);
        level++;
        rec(n,m);
        level--;
        num-=i*binpow(10,n-level)+i*binpow(10,level-1);}
        
    }
}
signed main()
{
    cin>>a>>b;
    lli nb=noofdg(b);// no of digits in b
    for(lli i=1;i<=nb;i++)
    { 
    lli m;
    if(i&1)
    {
    m=i/2+1;
    } 
    else
    m=i/2;
    rec(i,m);
    }
    cout<<ct;
    
}
/*#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
lli countdigit(lli x)
{
    if(x>=2 && x<=9)
    return 1;
    lli ct=0;
    while(x!=0)
    {
        ct++;
        x=x/10;
    }
    return ct;
}
bool valid (lli x,lli a,lli b)
{
    bool  f1,f2;
    f1=false;
    f2=false;
    lli ct=0;
    if(x==1)
    f1=false;
    else if(x==2)
    f1=true;
    else if(x==3)
    f1=true;
    else if (x%2==0 || x%3==0  )
    f1=false;
    else 
    {
        for(lli i=1;i*i<=x;i++)
        {
                 if(ct>2)
                 break;
                 if(i*i==x)
                 ct+=1;
                 else if (x%i==0)
                 ct+=2;
                 else 
                 continue;
        
         }
    }
    if(ct==2)
    f1=true;
    if(x>=a && x<=b)
    f2=true;
    if(f1&&f2)
    return true;
    else 
    return false;
}
vector<int> pwr;
void powerof10()
{
 
    lli ans=1;
    pwr.push_back(ans);
    for(lli i=1;i<=9;i++)
    {
        ans=ans*10;
        pwr.push_back(ans);

    }
}
void rec(lli nd,vector<int>&arr,lli pn,lli a,lli b,lli &ct)
{
    if(pn>(nd-1)/2)
    {
        // check for range  and prime 
        lli num=0;
        for(lli k=0;k<nd;k++)
        {
            
            num+=arr[nd-1-k]*pwr[k];
        }

        bool flag=valid(num,a,b);
        if(flag)
        { ct++;
        }

        return;
    }
    for(lli i=0;i<=9;i++)
    {
        if(i==0 && pn==0 )
        continue;

            arr[pn]=i;
            arr[nd-1-pn]=i;
            rec(nd,arr,pn+1,a,b,ct);
            // cout<<"array values"<<endl;
            // for(auto x:arr)
            // cout<<x<<endl;
        
    }
}
signed main()
{
    lli a,b;
    cin>>a>>b;
    lli ct=0;
    powerof10();
    lli c,d;
    c=countdigit(a);
    d=countdigit(b);
    for(lli i=c;i<=d;i++)
    {
     
        vector<int> arr;
        arr.resize(i);
        
        rec(i,arr,0,a,b,ct);
        
    }
    cout<<ct<<endl;
}*/