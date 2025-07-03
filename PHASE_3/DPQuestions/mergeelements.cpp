#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int n;
vector<int>arr;
#define inf 1e9
int dp[503][503];
vector<int> ps;
int rec(int l,int r)
{
    if(l==r)
    return 0;

    if(dp[l][r]!=-1)
    return dp[l][r];

    int ans=inf;
    
    for(int mid=l;mid<r;mid++)
    {
        int sum2=ps[mid]-ps[l-1];
        int sum1=ps[r]-ps[mid];
        ans=min(ans,rec(l,mid)+rec(mid+1,r)+(sum2*(sum1)));
    }
    return dp[l][r]=ans;
}
signed main(){
    cin>>n;
    arr.resize(n+2);
    ps.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(i==1)
        {
            ps[i]=arr[i];
            ps[i]%=100;
        }
        else 
        {
            ps[i]=ps[i-1]%100+arr[i]%100;
            ps[i]%=100;
        }
    }
    ps[0]=0;

    memset(dp,-1,sizeof(dp));
    cout<<rec(1,n)<<endl;
}