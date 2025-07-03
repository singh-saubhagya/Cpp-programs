#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define inf 1e9
string a,b;
int n,m;
vector<vector<int>> dp;
int rec(int i,int j){

    
    if(i<n && j==m)
    {
        return n-i;
    }
    if(i==n && j<m)
    {
        return m-j;
    }
    if(i==n && j==m)
    return 0;// pruning

    if(dp[i][j]!=-1)
    return dp[i][j];
 
    int ans=1e9;
    ans=min(ans,rec(i+1,j)+1);
    ans=min(ans,rec(i,j+1)+1);
    if(a[i]==b[j])
    ans=min(ans,rec(i+1,j+1)+1);
    return dp[i][j]=ans;

}
vector<char> ans;
signed main(){
    cin>>a>>b;
    n=a.length();
    m=b.length();
    dp=vector<vector<int>>(n+2,vector<int>(m+2,-1));
    cout<<rec(0,0);
    
}