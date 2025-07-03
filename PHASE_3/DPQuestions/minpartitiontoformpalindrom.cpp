#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define inf 1e9
string str;int n;
vector<vector<int>>dp1;
vector<int> dp2;
int rec1(int i, int j)
{
    if(i<0 || j<0)
    return 0;
    if(j-i+1<=1)
    {
        return 1;
    }
    if(dp1[i][j]!=-1)
    {
        return dp1[i][j];
    }

    int ans=0;
    if(str[i]==str[j] && rec1(i+1,j-1))
    {
        ans=1;
    }
    return dp1[i][j]=ans;

}
int rec2(int i)
{
    if(i==-1)
    {
        return 0;
    }

    if(dp2[i]!=-1)
    {
        return dp2[i];
    }
    int ans=inf;
    for(int j=0;j<=i;j++)
    {
        if(rec1(j,i))
        {
            ans=min(ans,1+rec2(j-1));
        }
    }
    return dp2[i]=ans;
}
signed main(){
   
    cin>>str;
    n=str.length();
    dp1=vector<vector<int>>(n+1,vector<int>(n+1,-1));
    dp2=vector<int>(n+1,-1);
    cout<<rec2(n-1)<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<dp2[(i)]<<endl;
    }

}