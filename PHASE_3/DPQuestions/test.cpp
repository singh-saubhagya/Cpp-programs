#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
int solve(int x)
{
    if(x&1)// odd losing 
    return 0;
    
    if((x&(x-1))==0)// power of 2 
    {
        int ct=0;
        int n=x;
        while(n!=1)
        {
            ct++;
            n/=2;
        }
        if(ct&1)
        return 0;
        return 1;
    }
    return 1;

}


signed main()
{
  cin.tie(0); cout.tie(0);
  cout<<solve(10);
}