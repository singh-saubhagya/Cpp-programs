#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
vector<vector<lli >> arr;
vector<vector<bool>> mark;
vector<vector<lli >> dp;
#define inf 1e9
lli  n,m;
lli  rec(lli  i,lli  j){
    if(i==n-1 && j==m-1 )
    return arr[n-1][m-1];
    if(i>=n || j>=m)
    return -inf;
    if(mark[i][j]){
        return dp[i][j];
    }
    mark[i][j]=true;
    dp[i][j]=arr[i][j] + max(rec(i,j+1),rec(i+1,j));
    return dp[i][j];
}
signed main(){
   
    cin>>n>>m;
    arr.resize(n);
    mark.resize(n);
    dp.resize(n);
    for(lli  i=0;i<n;i++){
        arr[i].resize(m);
        mark[i].resize(m);
        dp[i].resize(m);
        for(lli  j=0;j<m;j++){
            lli  x;
            cin>>x;
            arr[i][j]=x;
            mark[i][j]=false;
            dp[i][j]=-inf;
        }
    }
    lli  ans=rec(0,0);
    cout<<ans<<endl;
    
}