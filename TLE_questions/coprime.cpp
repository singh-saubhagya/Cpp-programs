#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
vector<vector<int>> cp;
void solve()
{
    int n;
    cin>>n;
    vector<int> arr(n+2);
    for(int i=1;i<=n;i++)cin>>arr[i];
    unordered_map<int,int> m;
    for(int i=1;i<=n;i++)
    {
        m[arr[i]]=i;
    }
    int ans=-1;
    for(int i=n;i>=1;i--)
    {
        for(auto x:cp[arr[i]])
        {
            if(m[x]>0)
            {
                ans=max(ans,m[x]+i);
            }
        }
    }
    cout<<ans<<endl;

}
int findgcd(int a,int b)
{if(a==0)
return b;
return findgcd(b%a,a);
}
signed main()
{
    int t;
    cin>>t;
    cp.resize(1003);
    for(int i=1;i<=1000;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(findgcd(i,j)==1)
            {
                cp[i].push_back(j);
            }
        }
    }
    while(t--)solve();
}