#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int ans=1;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
          ans=n/i;
          break;
        }
    }
    int a=min(n-ans,ans);
    int b=max(n-ans,ans);
    cout<<a<<" "<<b<<endl;
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    solve();}