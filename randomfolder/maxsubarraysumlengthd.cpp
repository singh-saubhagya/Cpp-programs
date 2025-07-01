#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'

void solve()
{
  lli n,d;
  cin>>n>>d;
vector<lli> arr;
vector<lli> presum(n+1,0);
  int sum=0;
  for(int i=0;i<n;i++)
  {
    int x;
    cin>>x;
    arr.push_back(x);
    sum+=x;
    presum[i]=sum;   
  }
  lli ans; 
  lli minindex;
  for(int r=d-1;r<n;r++)
  {
    int l=r-d+1;
    int z=l-1;
    if(z==-1)
    {
      ans=presum[r];
      minindex=-1;
      presum[minindex]=ans;
    }
    else
    {
      if(presum[z]<(minindex==-1?0:presum[minindex]))
      {
          minindex=z;
      }
    }
          int k=presum[r]-(minindex==-1?0:presum[minindex]);
          if(k>ans)
            {
            ans=k;
            }
  }
  cout<<ans<<endl;


}


signed main()
{
  lli q;
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cout<<endl;

 
  solve();
  
  

}