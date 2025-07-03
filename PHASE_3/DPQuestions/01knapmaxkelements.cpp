#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
int n,W;
int k;
int dp[101][101][101];
vector<pair<int,int>> arr;
#define inf 1e9
int rec(int i,int j,int l){
    // pruning

    if (l > k) return -1e9;
    if (i == n) return 0;
    if(dp[i][j][l]!=-1)
    return dp[i][j][l];
    int ans=rec(i+1,j,l);

    if(j>=arr[i].first)
    {
       if(l<k)
       {
        ans=max(ans,rec(i+1,j-arr[i].first,l+1)+arr[i].second);
       }
       
    }
    
    return dp[i][j][l]=ans;
}

signed main(){
    cin>>n>>W>>k;
    arr.resize(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        arr[i]={a,b};
    }
    memset(dp,-1,sizeof(dp));
    int target=rec(0,W,0);
    cout<<target<<endl;
  
}