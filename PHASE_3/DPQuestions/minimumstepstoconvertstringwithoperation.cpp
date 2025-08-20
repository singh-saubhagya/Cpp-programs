#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
string word1,word2;
int dp[110][110];
int n;
const int inf=1e9;
int rec(int l,int r)
{
    
    if(l<0 || r<0 || l>=n || r>=n)
    return inf;

    string temp1=word1.substr(l,r-l+1);
    string temp2=word2.substr(l,r-l+1);
    if(temp1==temp2)
    return 0;

    if(dp[l][r]!=-1)
    return dp[l][r];

    // replace 
    int ans=inf;
    for(int i=l;i<=r;i++)
    {
        if(word1[i]!=word2[i])
        {
            char temp=word1[i];
            word1[i]=word2[i];
             string temp11=word1.substr(l,r-l+1);
             string temp22=word2.substr(l,r-l+1);
             if(temp11==temp22)
             return 1;
             else 
             word1[i]=temp;
        }
      
        
    }
    // swap
    char ch1,ch2;
    ch1=word1[l];
    ch2=word2[l];
    for(int i=l+1;i<=r;i++)
    {
        if(word1[i]==ch2 && ch1==word2[i])
        {
            swap(word1[l],word1[i]);
            ans=min(ans,1+rec(l+1,i-1)+rec(i+1,r));
            swap(word1[l],word1[i]);
        }
    }
    // reverse
    int len=r-l+1;

    for(int i=2;i<=len;i++)
    {
        string rev1=word1.substr(l,i);
        string rev2=word2.substr(l,i);
        int st=l;
        int en=l+i-1;
        reverse(rev1.begin(),rev1.end());
        if(rev1==rev2)
        {
            ans=min(ans,1+rec(en+1,r));
        }
    }
    cout<<l<<" "<<r<<" "<<ans<<endl;
    return dp[l][r]=ans;
}
void solve()
{
    memset(dp,-1,sizeof(dp));
    cin>>word1>>word2;
    n=word1.length();
    cout<<rec(0,n-1);
}
signed main()
{
  cin.tie(0); cout.tie(0);
  solve();
}