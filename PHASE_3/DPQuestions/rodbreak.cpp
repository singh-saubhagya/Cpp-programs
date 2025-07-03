/*
Question: We have a rod of length l and it has n breaking points between its ends, and breking at p point , will give benifit equal to length of rod before breaking . 
so we have to maximize the benifit after breaking at all the n points. 

Form 4 : interval or lr dp
state : dp[l][r], so we have taken a subarray from l to r, and try to find the most optimal answer for it.
Transition : checking for all the breaking points available for(int p=l+1;p<r;p++)  ans=max(ans,rec(l,p)+rec(p,r)+ arr[r]-arr[l]);
T.C: N^3

*/

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
vector<int> arr;
int dp[102][102];
int rec(int l,int r){
    if(r-l==1 || r-l==0)
    return 0;
    
    if(dp[l][r]!=-1)
    {
        return dp[l][r];
    }
    int ans=-1e9;
    for(int p=l+1;p<r;p++)
    ans=max(ans,rec(l,p)+rec(p,r)+ arr[r]-arr[l]);

    return dp[l][r]=ans;    
}
signed main(){
    int l;
    cin>>l;// length of the rod
    int n;
    cin>>n;// no of breaking points 
    arr.resize(n+3);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    arr[0]=0;// here the whole array is treated as rod, whose index from 1 to n, denotes the breaking points between 0,L(L : length of the rod).
    arr[n+1]=l;
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,n+1);
}