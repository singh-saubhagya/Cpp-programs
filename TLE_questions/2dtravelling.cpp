#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
void solve(){
    lli n,k,a,b;
    cin>>n>>k>>a>>b;
    vector<pair<lli,lli>> arr(n+2);
   

    for(lli i=1;i<=n;i++)
    {
        lli p,q;
        cin>>p>>q;
        arr[i]={p,q};
       
     
    }
    if(a<=k && b<=k)
    {
        cout<<0<<endl;
        return;
    }
    else if(a<=k )
    {
        lli ans=1e18;
        for(int i=1;i<=k;i++)
        {
            ans=min(ans,abs(arr[b].first-arr[i].first)+abs(arr[b].second-arr[i].second));
        }
        cout<<ans<<endl;return;
    }
    else if (b<=k)
    {
        lli ans=1e18;
        for(int i=1;i<=k;i++)
        {
            ans=min(ans,abs(arr[a].first-arr[i].first)+abs(arr[a].second-arr[i].second));
        }
        cout<<ans<<endl;return;
    }
    else 
    {
        lli ans=abs(arr[a].first-arr[b].first)+abs(arr[a].second-arr[b].second);


        lli ans1=1e18;
        for(int i=1;i<=k;i++)
        {
            ans1=min(ans1,abs(arr[b].first-arr[i].first)+abs(arr[b].second-arr[i].second));
        }
        lli ans2=1e18;
        for(int i=1;i<=k;i++)
        {
            ans2=min(ans2,abs(arr[a].first-arr[i].first)+abs(arr[a].second-arr[i].second));
        }
        cout<<min(ans,ans1+ans2)<<endl;
        return;
    }

}
signed main()
{
    int t;
    cin>>t;
    while(t--)solve();
}