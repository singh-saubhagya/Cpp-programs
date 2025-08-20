#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
const lli p=1e9+7;
lli binpow(lli val2,lli pp)
{
    if(val2==1)
    return 1; 
    if(pp==0)
    return 1;

    if(pp&1)
    {
        lli val=(val2*binpow(val2,pp-1))%p;
        return val;
    }
    else 
    {
        lli val=(binpow(val2,pp/2))%p;
        val=(val*val)%p;
        return val;
    }

}
lli findcombination(int n,int k)
{
    lli a=n+k-1;
    lli b=2*k;
    lli c=a-b;
    if(c<b)
    swap(c,b);
    lli val1=1;
    for(int i=a;i>c;i--)
    {
        val1=(val1*i)%p;
    }
    lli val2=1;
    for(int i=b;i>1;i--)
    {
        val2=(val2*i)%p;
    }
    val2=binpow(val2,p-2);
    lli fa=(val1*val2)%p;
    return fa;
}
void solve(int n, int k)
{
    lli ans=findcombination(n,k);
    cout<<ans<<endl;
}
signed main()
{
  cin.tie(0); cout.tie(0);
  int a,b;
  cin>>a>>b;
  solve(a,b);
}