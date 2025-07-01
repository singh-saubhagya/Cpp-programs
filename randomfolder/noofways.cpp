#include<bits/stdc++.h>
using namespace std;
typedef long long lli;

lli p=1e9 +7;
vector<lli> x;
const int m =3e5;
vector<lli> v(m+1);
lli binpow(lli b,lli p,lli mod){lli ans=1;b%=mod;for(;p;p>>=1){if(p&1)ans=ans*b%mod;b=b*b%mod;}return ans;}
/*We are pre calculating the factorial of all the no in the range 1 to 1e5 so that we don't need 
to calculate for each test case separately which will increase its time complexity;

Time complexity:O(m+qlog(mod))
*/

void findfactorial()
{
    v[0]=1;
    for(lli i=1;i<=m;i++)
    {
        v[i]=(i*v[i-1])%p;
    }


}

void solve()
{
    lli n,m;
    cin>>n>>m;
    n%=p;
    m%=p;
    lli x1=v[(n+m)%p];
    lli x2=v[n];
    lli x3=v[m];
    x2=binpow(x2,p-2,p);
    x3=binpow(x3,p-2,p);
    lli result=(x1*x2)%p;
    result=(result*x3)%p;
    x.push_back(result);

}
signed main()
{
    int q;
    cin>>q;
    findfactorial();
    while(q--)
    {
        solve();
    }
    cout<<endl;
    for(lli i:x)
    {
        cout<<(i%p+p)%p<<endl;
    }
}


