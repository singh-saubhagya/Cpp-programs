#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
void solve()
{
    int n;
    cin>>n;int ct=1;
    if(n&1)
    cout<<-1<<endl;
    
    else 
    {
         for(int i=1;i<=n;i+=2)
         {
            cout<<ct<<" "<<ct<<" ";
            ct+=1;
         }
        
    }
    cout<<endl;
    return ;
}
signed main()
{
  cin.tie(0); cout.tie(0);
  int t;cin>>t;while(t--)solve();
}