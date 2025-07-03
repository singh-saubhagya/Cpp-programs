#include<bits/stdc++.h>
using namespace std;
int dp[102][1002];
int n;
vector<int> arr;
// this is the form 1 problem because , we know at each level we have choice whether to take the ith item or not. (follows Lccm framework).
// dp[i][left]: means we are at the ith element and we have left amount of weight remaining , and now we will check whether from i to n-1 , is there any subset of sum left , that can be formed or not .
// traniston fn : at the ith state with left remaining, we either take i ,and move to next element or we don't take the ith element and directly move to i+1,
// so dp[i][left]= rec(i+1,left) ||  rec(i+1,left-arr[i])
// we can use taken as the parameter in the state in place of left , but that would have created us two problem. 
// Problem 1: If we had query of different t , it would take us in the n*T*q, because in the base case we were going to check If(taken==T) or not , for each query we have to change this t and reintialize the dp array.
// Problem 2: Printing


// Time complexity using left(N*T+Q) : fine as heaven
// Time complexity using take (N*T*Q) : will result in tle
int rec(int i,int left)
{
    if(left<0)// pruning 
    return 0;
    if(i==n)// base case 
    {
        if(left==0)
        return 1;
        return 0;
    }

    if(dp[i][left]!=-1)
    return dp[i][left];

    int ans=0;
    ans=rec(i+1,left);// not taken the ith item 
    if(ans==0)
    {
        ans=rec(i+1,left-arr[i]);
    }
    return dp[i][left]=ans;

}
vector<int> sol;
void generate(int i, int left){
    if(i==n)
    return ;
    int ans=0;
    ans=rec(i+1,left);// didn't take the ith item
    if(ans)
    {
        generate(i+1,left);
    }
    else 
    {
        ans=rec(i+1,left-arr[i]);
        if(ans)
        {
            sol.push_back(i);
            generate(i+1,left-arr[i]);
        }
        else
        {
            generate(i+1,left);
        }
    }
}
signed main(){
    cin>>n;
    arr.resize(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    memset(dp,-1,sizeof(dp));
    int q;
    cin>>q;// this query approch is only possible becuase we have use left parameter inplace of taken , which makes the dp independent of amount of T and we don't have to reinitialize the dp array.
    
    while(q--){
        int T;
        cin>>T;
        cout<<rec(0,T)<<":";
        generate(0,T);
        for(auto x:sol)
        cout<<x<<",";
        cout<<endl;
        sol.clear();
    }
 
 
}