#include<bits/stdc++.h>
using namespace std;
#define inf 1e18
typedef long long lli;
signed main()
{
    lli t;
    cin>>t;
    while(t--)
    {
        lli n;
        cin>>n;
        vector<vector<lli>> arr;
        arr.resize(n+1);
        for(lli i=0;i<n;i++)
        {
            lli m;
            cin>>m;
            for(lli j=0;j<m;j++)
            {
                lli x;
                cin>>x;
                arr[i].push_back(x);
            }
            sort(arr[i].begin(),arr[i].end());
        }
    
        lli ans=0;
        lli a,b;
        a=inf,b=inf;
        for(lli i=0;i<n;i++)
        {
            ans+=arr[i][1];
            a=min(arr[i][0],a);
            b=min(arr[i][1],b);
        }
        ans=ans-b+a;
        cout<<ans<<endl;
    }
}