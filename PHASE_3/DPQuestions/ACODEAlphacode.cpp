#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'

/*

Form:   This is form 1, because we need to perform partition in the string of integers
        important thing to note down is we don't have to make partition of length not greater than 2 and minimum of lenght 1 atlest.alignas

State:  dp[i][a]: stores the no of ways to make 'a' partition from 0 to index i.

Transiton: so at the index i , we can have one single part as i and  one part as i-1 + i(concatinated), because there are 26 alphabets only.
only i : int ans1=dp[i-1][a-1]
i-1 and i: int ans2=dp[i-2][a-1]
ans = ans1+ans2;
dp[i][a]=ans;

Time complexity : length of integer * no of partitions  ͌ 

*/
lli dp[1001][1001];
string str;
lli  rec(lli  i,lli  a){
    if(i==-1)// base case 
    {
        if(a==0)
        return 1;
        return 0;
    }
    if(a<=0 || i<0)// pruning 
    return 0;

    // cache
    if(dp[i][a]!=-1)
    {
        return dp[i][a];
    }


    lli  ans1=rec(i-1,a-1);
    char ch=str[i-1];
    char ch2=str[i];
    lli  n=ch-'0';
    n=n*10;
    n+=ch2-'0';
    if(n<=26 && n>=1)
    {
        lli  ans2=rec(i-2,a-1);
        ans1+=ans2; 
    }
    lli  ans=ans1;
    return dp[i][a]=ans;

}
signed main(){
    cin>>str;
    memset(dp,-1,sizeof(dp));
    lli  n=str.length();
    lli  a=n/2-1;
    lli  ans=0;
    for( ;a<=n;a++)
    {
        ans+=rec(n-1,a);
    }
    cout<<ans;
}