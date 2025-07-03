#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr;
    arr.resize(n);
    int val=1e9;
    int ct=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {arr[i].resize(m);
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]<0)
            {
                ct++;
            }
            val=min(val,abs(arr[i][j]));
            sum+=abs(arr[i][j]);
        }
    }
    if(ct&1)
    {
        cout<<sum-2*val<<endl;
    }
    else 
    {
        cout<<sum<<endl;
    }
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    solve();
}