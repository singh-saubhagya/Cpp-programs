#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
lli solve(vector<lli>& height)
{
    lli st=0;
    lli en=height.size();
    en--;
    lli ans=INT_MIN;
    while(st<en)
    {
        ans=max(ans,min(height[st],height[en])*(en-st));
        if(height[st]<height[en])
        {
            st++;
        }
        else
        {
            en--;
        }

    }
    return ans;
}
signed main()
{
  vector<lli> arr;
  lli n;
  cin>>n;
  for(lli i=0;i<n;i++)
  {
    lli x;
    cin>>x;
    arr.push_back(x);
  }
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  
  cout<<endl;

  lli result=solve(arr);
 cout<<result;

}