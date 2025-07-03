// step 1 : form 1 , level by level , we are doing and making choices whether to take the item or not
// step 2 : state, dp[i][j]: we have maked choices till i-1 and we have j amt of  weight left , now we have to choose the best subset in the range i....n items which has weight less than j , and has maximum score
// step 3 : transition , select ith item and call  recursion dp[i+1,j-w[i]], or reject ith item cand call recurison dp[i+1,j];
// step 4 : time complex : n* W, : n : no of item , W, weight 

#include<bits/stdc++.h>
using namespace std;
int n,W;
int dp[3002][3002];
vector<pair<int,int>> arr;

int rec(int i,int j){
    // pruning
   

    if(i==n)// base case 
    {
        return 0;
    }

    if(dp[i][j]!=-1)
    return dp[i][j];
    int ans=rec(i+1,j);

    if(j>=arr[i].first)
    {
       ans=max(ans,rec(i+1,j-arr[i].first)+arr[i].second);// take the ith element and move to next element , i+1 th
    }
    return dp[i][j]=ans;
   
   

}
vector<int> it;
void generate(int i,int j){
   if(i==n)
   return;
   else 
   {
        int dontake=rec(i+1,j);
        if(j>=arr[i].first){
            int take=rec(i+1,j-arr[i].first);
            if(take>=dontake)
            {
                it.push_back(i);
                generate(i+1,j-arr[i].first);
            }
            else
            {
                generate(i+1,j);
            }
        }
        else
        {
            // cantake,
            generate(i+1,j);
        }
   }

}
signed main(){
    cin>>n>>W;
    arr.resize(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        arr[i]={a,b};
    }
    memset(dp,-1,sizeof(dp));
    int target=rec(0,W);
    cout<<target<<endl;
    generate(0,W);
    for(auto x:it)
    cout<<x<<endl;
}