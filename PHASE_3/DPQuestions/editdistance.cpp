#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
const int inf=1e9;
int dp[510][510];   
string word1,word2;
int a,b;
int rec(int i,int j)
{
    if(i==a)// base case
    {
        if(j==b)
        return 0;
        return b-j;// inserting left character
    }
    if(j==b)
    {
        return a-i; // deleting extra character
    }
    if(dp[i][j]!=-1)
    return dp[i][j];

    int ans=inf;
    if(i<a && j<b && word1[i]==word2[j])
    {
        ans=min(ans,rec(i+1,j+1));
    }
    ans=min(ans,1+rec(i+1,j));// deleting the character
    ans=min(ans,1+rec(i+1,j+1));// replacing the character
    ans=min(ans,1+rec(i,j+1));// inserting the character
    return dp[i][j]=ans;

}
void generate(int i,int j)
{
    if(i==a)// base case
    {
        if(j==b)
        return ;
        cout<<"inserting extra character "<<b-j<<endl;// inserting left character
        return ;
    }
    if(j==b)
    {
        cout<<"deleting extra character "<<a-i<<endl; // deleting extra character
        return ;
    }
    int ans=rec(i,j);
    if(i<a && j<b && word1[i]==word2[j])
    {
        if(ans==rec(i+1,j+1))
        {
            cout<<"NO operation at this indexe's "<<endl;
            generate(i+1,j+1);
            return ;
        }
    }
    if(ans==1+rec(i+1,j))
    {
        cout<<"deleting the character "<<word1[i]<<endl;
        generate(i+1,j);
        return;
    }
    if(ans==1+rec(i+1,j+1))
    {
        cout<<"Replacing the character "<<word1[i]<<" by " << word2[j]<<endl;
        generate(i+1,j+1);
        return ;
    }
    if(ans==1+rec(i,j+1))
    {
        cout<<"Inserting the character "<<word2[j]<<endl;
        generate(i,j+1);
        return;
    }
}
void solve()
{
    memset(dp,-1,sizeof(dp));
    cin>>word1>>word2;
    a=word1.size();
    b=word2.size();
    cout<<rec(0,0)<<endl;
    generate(0,0);

}
signed main()
{
  cin.tie(0); cout.tie(0);
  solve();
}