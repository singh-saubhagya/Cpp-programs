/*
Test case : 1 2 3 3 4 4 4 2 5 1 6
answer is 4, remove {4,4,4} then {5} and {6} then remaining {1, 2, 3, 3, 2, 1}

there are 3 transition , @1, @2, @3

rec(1,11)(1 indexed based)
the @2, will find the endpoint for 1, go call rec(2,9) + rec(11,11)
the rec(2,9) will find endpoint of 2 index  at 8 index and call rec(3,7) + rec(9,9)
rec(3,7) will find its endpoint at 4 index and call recursion as rec(4,3) and + rec(5,7) 
and we know rec(4,3) values to 1 and rec(5,7) values to 1 , therefor rec(3,7) sum to 2 
rec(9,9) : 1 , so rec(2,9): 3 , rec(11,11): 1 , so rec(1,11) values to 4

the @2 transition helps us to find the subarray in the array which needs to be deleted first in order to make rest of the palindrom. 
*/


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define inf 1e9
int n;
vector<int> arr;
int dp[102][102];
int rec(int l, int r)
{
   
    if(l-r>1)// pruning 
    return inf;// invalid 

    if(l-r==1 || l-r==0 )
    return 1;

    if(dp[l][r]!=-1)
    return dp[l][r];

    int ans=inf;
    if(arr[l]==arr[r])
    {
        ans=min(ans,rec(l+1,r-1));// @1
    }
   
    for(int i=l+1;i<=r-1;i++)
    {
        if(arr[i]==arr[l])//@2
        {
            ans=min(ans,rec(l+1,i-1)+rec(i+1,r)); // using this we are finding subarray which can be palindrome , starting point of subarray is l and ending is i, so arr[l]==arr[i], and rec(l+1,i-1) means no of ways to make it palindrom . and for the rest range we have used i+1 to r.
        }
    }
     ans=min(ans,1+rec(l+1,r)); //@3  this is the case when there are palindrom of length 1 , or we can say the element is distinct in the array, so we need 1 cost to delete it .
    // cout<<l<<" "<<r<<" "<<ans<<endl;
    return dp[l][r]=ans;

}
signed main()
{
    int t;
    cin>>t;
    
    while(t--)
    {

        cin>>n;
        arr.resize(n+2);
        for(int i=1;i<=n;i++)
        cin>>arr[i];
        memset(dp,-1,sizeof(dp));
        cout<<rec(1,n)<<endl;
        // for(int i=0;i<=n;i++)
        // {
        //     for(int j=0;j<=n;j++)
        //     {
        //         cout<<dp[i][j];
        //     }
        //     cout<<endl;
        // }
    }
}