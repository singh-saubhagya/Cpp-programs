// count all the valid sequence of parenthesis , such that their depth is atmost k
#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
lli  dp[1001][1001];lli  n,k;
lli  rec(lli  i,lli  d){
    if(d>k || d<0 )// pruning
    {
        return 0;
    }
    if(i==n)// base case 
    {
        if(d==0)
        return 1;
        else return 0;
    }
    if(dp[i][d]!=-1)// cache
    return dp[i][d];

    dp[i][d]=rec(i+1,d+1)+rec(i+1,d-1);// transition      
    return dp[i][d];
}

void generate(lli  i , lli  d,vector<char> &str){// i: current level , d: current depth
    // first we add opening braces
    if(i==0)
    {
        for(lli  i=1;i<=n;i++)
        cout<<str[i];
        cout<<endl;
        return ;
    }
    if( dp[i-1][d-1]!=-1)
    {
        str[i]='(';
        generate(i-1,d-1,str);
    }
    if(dp[i-1][d+1]!=-1)
    // remove this comment and then we can able to generate all the sequence of parenthesis
  // else
    {
        str[i]=')'; 
        generate(i-1,d+1,str);
    }
    return ;
    
}
signed main(){

    cin>>n>>k;  
    memset(dp,-1,sizeof(dp));
    rec(0,0);
    cout<<dp[0][0]<<endl;
    vector<char > str;
    str.resize(n+1);
    str[n]=')';
    generate(n-1,1,str);
}