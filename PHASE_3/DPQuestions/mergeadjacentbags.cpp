/*
    Question : WE have n bags, and we can merge any two adjacent bags at a time , and after merging the new value of the bag is (x+y)%100, and we get a benifit of x*y.
    suppose we have done completed merging and the final vaule of the bag is gonna be always (val(1)+val(2)+val(3)....val(n) )%100
    Maximize the benifit .

    Form : 4, (why not 2 , because after merging we have to store new values, and done processing again with the  new value which is not possible in form 2)
    State dp[l][r]: the max benifit we get after mergin all the elements in the subarray l to r
    
    Transiton : Check for all mid in range l to r, such that dp[l][r] is max;
      max(mid: l+1,l+2....r-l) [  rec(l,mid)+rec(mid+1,r)+sum{l to mid}* sum{mid+1 to r} ]
*/

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int n;
vector<int> arr;
int dp[102][102];
int rec(int l,int r){
    if(l==r)
    return 0;

    if(dp[l][r]!=-1)
    return dp[l][r];
    int ans=-1e9;
    int sum1=0;
    int sum2=0;
    for(int i=l;i<=r;i++)
    {
        sum2+=arr[i];
    }
    for(int mid=l;mid<r;mid++)
    {
        sum1+=arr[mid];
        ans=max(ans,rec(l,mid)+rec(mid+1,r)+sum1*(sum2-sum1));
    }
    return dp[l][r]=ans;

}
vector<pair<int,int>> sol;
void generate(int l, int r){


    if(l>=r)
    return ;
    int ans=-1e9;
    int sum1=0;
    int sum2=0;
    for(int i=l;i<=r;i++)
    {
        sum2+=arr[i];
    }
    pair<int,int> temp;
    int it;
    for(int mid=l;mid<r;mid++)
    {
        sum1+=arr[mid];
        
        if(rec(l,mid)+rec(mid+1,r)+sum1*(sum2-sum1)>ans)
        {
            ans=rec(l,mid)+rec(mid+1,r)+sum1*(sum2-sum1);
            temp={sum1,sum2-sum1};
            it=mid;
        }
    }
    sol.push_back(temp);
    generate(l,it);
    generate(it+1,r);
    return;

}
signed main(){
    cin>>n;    
    arr.resize(n+1);
    for(int i=1;i<=n;i++)
    cin>>arr[i];
   
    memset(dp,-1,sizeof(dp));
    cout<<rec(1,n)<<endl;
    generate(1,n);
    reverse(sol.begin(),sol.end());
    for(auto x:sol)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }
}