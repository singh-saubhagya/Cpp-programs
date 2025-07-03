// form 2
// state: dp[i], longest common subseq ending at index i. 
// transiton: check all the prev index i.e <i such that the length is max , but look for the condn arr[x]<arr[i], 
// T.C: n^2;

#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
int n;
vector<int> arr;
int dp[1001];
int rec(int i)
{
    if(i<0)// and pruning
    return 0;

    if(dp[i]!=-1)
    return dp[i];

    int ans=1;
    for(int pv=0;pv<i;pv++)
    {
        if(arr[pv]<arr[i])
        {
            ans=max(ans,1+rec(pv));
        }
    }
    return dp[i]=ans;

}
vector<int> sol;
void generate(int i)
{
    if(i<0)
    return;
    int ans=1;
    int it=-1;
    sol.push_back(arr[i]);
    for(int pv=0;pv<i;pv++)
    {
        if(arr[pv]<arr[i])
        {
            int ans2=1+rec(pv);
            if(ans2>ans)
            {
                it=pv;
                ans=ans2;
            }
        }
    }
    generate(it);

}
signed main(){
    cin>>n;
    arr.resize(n+1);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    memset(dp,-1,sizeof(dp));
    int ans=0;
    int it=0;
    for(int i=0;i<n;i++)
    {   
        if(rec(i)>ans)
        {
            it=i;
            ans=rec(i);
        }
    }
    cout<<ans<<endl;
    generate(it);
    for(auto x:sol)
    cout<<x<<" ";

}
