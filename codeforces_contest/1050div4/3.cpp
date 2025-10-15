#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> arr;
    arr.push_back({0,0});
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        arr.push_back({a,b});
    }
    int last=arr[n].first;
   
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int cur=arr[i].first;
        int gp=arr[i].second;

        int ncur=arr[i+1].first;
        int ngp=arr[i+1].second;
        int diff=ncur-cur;
        if(gp==ngp)
        {
            if(diff&1)
            {
                ans+=diff-1;
            }
            else ans+=diff;
        }
        else 
        {
            if(diff&1)
            {
                ans+=diff;
            }
            else 
            ans+=diff-1;
        }
    }
    ans+=m-last;
    cout<<ans<<endl;
}
signed main()
{
  cin.tie(0); cout.tie(0);
  int t;cin>>t;while(t--)solve();
}