#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
 const lli k=1e9+7;
vector<vector<lli>> arr;
vector<vector<lli>> presum;
vector<lli> result;
lli n,m,q;
void create_prefixsum()
{
    presum=vector<vector<lli>>(n,vector<lli>(m,0));

    for(lli i=0;i<n;i++)
    {
        for(lli j=0;j<m;j++)
        {
            if(i==0 || j==0)
            {
                if(i==0 && j==0)
                {
                     presum[i][j]=arr[i][j];
                     presum[i][j]= (presum[i][j]%k+k)%k;
                     
                }
                else if(j==0)
                {
                     presum[i][j]=arr[i][j]+presum[i-1][j];
                     presum[i][j]= (presum[i][j]%k+k)%k;
                }
                else
                {
                     presum[i][j]=arr[i][j]+presum[i][j-1];
                     presum[i][j]= (presum[i][j]%k+k)%k;
                }
                
            }
            else 
            {
                presum[i][j]=(arr[i][j]+presum[i-1][j])%k+(presum[i][j-1]-presum[i-1][j-1])%k;
                presum[i][j]= (presum[i][j]%k+k)%k;
            }
        }
    }
}
void find_ansTOquery(lli x1, lli x2, lli y1, lli y2)
{
    lli ans;
    x1--;//0
    x2--;//1
    y1--;//0
    y2--;//1
    // converting into 0 based index;
    if(x1==0 && y1==0)
    {
        ans=presum[x2][y2];
    }
    else if (x1==0)
    {
        
        ans=presum[x2][y2]-presum[x2][y1-1];
        
        
    }
    else if (y1==0)
    {
        
         ans=presum[x2][y2]-presum[x1-1][y2];
        
    }
    else
    ans=(presum[x2][y2]-presum[x1-1][y2])%k+(-presum[x2][y1-1]+presum[x1-1][y1-1])%k;
    ans=(ans%k+k)%k;
    result.push_back(ans);
    
}
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cin>>n>>m>>q;
  arr=vector<vector<lli>>(n,vector<lli>(m,0));
  for(lli i=0;i<n;i++)
  {
    for(lli j=0;j<m;j++)
    {
        lli x;
        cin>>x;
        arr[i][j]=x%k;
    }
  }
  create_prefixsum();
  for(lli i=0;i<q;i++)
  {
    lli x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    find_ansTOquery(x1,x2,y1,y2);

  }
  for(lli x:result)
  {
    cout<<x<<endl;
  }
  
}