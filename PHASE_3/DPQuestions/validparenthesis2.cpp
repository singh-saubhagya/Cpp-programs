// count all the valid sequence of parenthesis , such that their depth is  k 

#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001][2];
int n,k;
int rec(int i,int d, int seenk){
    if(d<0 || d>k )
    return 0;
    if(i==n){
        if(d==0 && seenk== 1)
        return 1;
        return 0;
    }
    if(dp[i][d][seenk]!=-1)
    return dp[i][d][seenk];

    dp[i][d][seenk]=rec(i+1,d+1,d+1==k || seenk) + rec(i+1,d-1,seenk);
    return dp[i][d][seenk];

}
signed main(){
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    rec(0,0,0);
    cout<<rec(0,0,0);
}