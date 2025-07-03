#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
lli n;
vector<int> arr;
int dp[1002][1002];


// form 1;
// state, dp[i][j]: stores the longest inc subsequence in the range i to n-1 index, if the last element choosen is at index x. 
// transition : don't take the ith element and move to next index , or take the ith element and move to next index, update the last element take index to i.
int rec(int i,int x)
{
    if(i==n)// base case
    return 0;

    if(dp[i][x]!=-1)// cache check
    return dp[i][x];

  
    int ans=(rec(i+1,x));// didn't take the ith element;
    if(arr[i]>arr[x])
    {
        ans=max(ans,1+rec(i+1,i));// take the ith element , so adding 1 and moving to next state 
    }
    return dp[i][x]=ans;
}
vector<int>ans;
void generate(int i , int x){
    if (i==n)
    return;

    int ans1=rec(i+1,x);
    
    if(arr[x]<arr[i])
    {
        int ans2=1+rec(i+1,i);
        if(ans2>ans1)
        {
            ans.push_back(arr[i]);
            generate(i+1,i);
        }
        else
        {
            generate(i+1,x);
        }
        
    }
    else 
    {
        generate(i+1,x);
    }
}
signed main(){
    cin>>n;
    arr.resize(n+1);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    arr[n]=-1;// taking assumption that -1 is not present in the array.
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,n);// taking assumption that -1 is not present in the array.
    generate(0,n);
    cout<<endl;
    for(auto x:ans)
    cout<<x<<" ";
}