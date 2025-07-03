#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> arr;
int dp[100002][4];
int rec(int i,int ch){
    // 
    // base case 
    if(i==n+1)
    return 0;

    if(dp[i][ch]!=-1)
    {
        return dp[i][ch];
    }
    else if (ch==1)
    {
        int ans1,ans2;
        int ans;
        ans1=rec(i+1,2)+arr[i][1];// b chosen
        ans2=rec(i+1,3)+arr[i][2];// c chosen
        if(ans1>ans2)
        ans=ans1;
        else 
        ans=ans2;
        return dp[i][ch]=ans;

    }
    else if (ch==2)
    {
        int ans1,ans2;
        int ans;
        ans1=rec(i+1,1)+arr[i][0];// a chosen
        ans2=rec(i+1,3)+arr[i][2];// c chosen
        if(ans1>ans2)
        ans=ans1;
        else 
        ans=ans2;
        return dp[i][ch]=ans;
    }
    else
    {
        int ans1,ans2;
        int ans;
        ans1=rec(i+1,2)+arr[i][1];// b chosen
        ans2=rec(i+1,1)+arr[i][0];// a chosen
        if(ans1>ans2)
        ans=ans1;
        else 
        ans=ans2;
        return dp[i][ch]=ans;
    }

}
signed main(){
    cin>>n;
    arr=vector<vector<int>>(n+1,vector<int>(4));
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        arr[i][0]=a;
        arr[i][1]=b;
        arr[i][2]=c;
    }
    
    memset(dp,-1,sizeof(dp));
    int ans1=rec(2,1)+arr[1][0];
    int ans2=rec(2,2)+arr[1][1];
    int ans3=rec(2,3)+arr[1][2];
    int ans=max(max(ans1,ans2),ans3);
    cout<<ans<<endl;
}