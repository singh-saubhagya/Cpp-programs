// form 2 => dp[i][j]: we have succesfully partitioned , till index i, with j partitions , such that sum is minimum of all max of the partitions.

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define inf 1e9
int n,k;
vector<int> arr;
int dp[1001][1001];
bool mark[1001][1001];
int rec(int i,int j){
    if(i==-1)// base case 
    {
        if(j==0)
        return 0;
        return inf;
    }
    if(i+1<j)// pruning 
    return inf;
   

    // cache check 
    if(mark[i][j]){
        return dp[i][j];
    }
    
    mark[i][j]=true;

    int lm=arr[i];// local max
    int ans=inf;
    for(int x=i;x>=0;x--){
        lm=max(arr[x],lm);
        ans=min(ans,rec(x-1,j-1)+lm);// here we can't directly write dp in place of ans, because we haven't initilised the dp , with inf.
    }
    return dp[i][j]=ans;

}
vector<int>print;

void generate(int i, int j)
{
    if(i==-1 && j==0)
    return;
    int lm=arr[i];
    for(int x=i;x>=0;x--){
        lm=max(arr[x],lm);
        if((rec(x-1,j-1)+lm)==dp[i][j])
        {
            print.push_back(x);
            break;
        }
    }
    generate(print.back()-1,j-1);
}
signed main(){

    cin>>n>>k;
    for(int i=0;i<n;i++){
    int x;cin>>x;arr.push_back(x);
    }
    memset(dp,0,sizeof(dp));
    memset(mark,false,sizeof(mark));
    cout<<rec(n-1,k)<<endl;
    generate(n-1,k);// only possible if solution exist.
    reverse(print.begin(),print.end());
    for(auto x:print)
    cout<<x<<" ";
}