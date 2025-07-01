#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
#define int long long

//you don't need to create vector of size 1e18 with datatype long long or int rather calculate the 
// difference at each mid point
vector<lli> result;
 
 lli sumofdigit(  lli n)
{
    if(n>=0 && n<=9)
    return n;
    lli sum=0;
    while(n!=0)
    {
          lli r=n%10;
        sum=sum+r;
        n=n/10;
    }
    return sum;
}
  lli check(  lli mid,  lli s)
{
    int sum=mid-sumofdigit(mid);
    if(sum>=s)
    return 1;
    else 
    return 0;
    // if(arr[mid]>=s)
    // {
    //     return 1;
    // }
    // else 
    // return 0;
}
void solve()
 {
      lli n,s;
      cin>>n>>s;
      lli lo=1,hi=n,ans=0;
      lli mid;
    while(lo<=hi)
    {
        mid=lo+(hi-lo)/2;
       if(check(mid,s)==1)
       {
        ans=mid;
        hi=mid-1;
       } 
       else
       {
        lo=mid+1;
       }
    }
    if(ans!=0)
    result.push_back(n-ans+1);
    else
    result.push_back(0);
 }
 signed main()
 {
     lli q;
   ios_base::sync_with_stdio(0);
   cin.tie(0);cout.tie(0);
   cin>>q;
   cout<<endl;
   while(q--)
   {
    solve();
   }
  
   for(lli i:result)
   {
    cout<<i<<endl;
   }

 }