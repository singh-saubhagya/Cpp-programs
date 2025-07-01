#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
lli binpow(lli b,lli p,lli mod){lli ans=1;b%=mod;for(;p;p>>=1){if(p&1)ans=ans*b%mod;b=b*b%mod;}return ans;}
/* here we have already pre defined a v vector which stores the factorial of a no up to m   */
const int m= 1e6; 
   vector<lli> v(m+1);
    lli  mod=1e9+7;
   
    void findfactorial()
    {
     v[0]=1;
        for(lli i=1;i<=m;i++) 
        {
                v[i]=(i*v[i-1])%mod;
        }
    }




 int main()
 {
    int n,r;
    findfactorial();
    cin>>n>>r;
    lli x1=v[n];
    lli x2=v[n-r];
    lli x3=v[r];
    x2=binpow(x2,mod-2,mod);
    x3=binpow(x3,mod-2,mod);
    lli result=(x1 *x3)%mod;
    result=(result *x2)%mod;
    cout<<result;

 }