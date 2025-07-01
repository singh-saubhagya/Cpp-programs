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

void ans_to_query(lli x1,lli x2,lli y1,lli y2,lli c)
{
 x1--;
 x2--;
 y1--;
 y2--;
 // 0 based index
 arr[x1][y1]+=c;
 if(y2==m-1 && x2==n-1)
 {
    return;
 }
 else if(y2==m-1)
 {
    arr[x2+1][y1]-=c;
    return ;
 }
 else if(x2==n-1)
 {
    arr[x1][y2+1]-=c;
    return ;
 }
 else
 {
        arr[x2+1][y1]-=c;
        arr[x1][y2+1]-=c;
        arr[x2+1][y2+1]+=c;
        return;
 }
}
lli create_prefixsum()
{
    presum=vector<vector<lli>>(n,vector<lli>(m,0));
    lli maximum=LLONG_MIN;
    for(lli i=0;i<n;i++)
    {
        for(lli j=0;j<m;j++)
        {
            if(i==0 || j==0)
            {
                if(i==0 && j==0)
                {
                     presum[i][j]=arr[i][j];
                     
                     if(presum[i][j]>maximum)
                     {
                        maximum=presum[i][j];
                     }
                     
                }
                else if(j==0)
                {
                     presum[i][j]=arr[i][j]+presum[i-1][j];
                     
                     if(presum[i][j]>maximum)
                     {
                        maximum=presum[i][j];
                     }
                }
                else
                {
                     presum[i][j]=arr[i][j]+presum[i][j-1];
                     
                     if(presum[i][j]>maximum)
                     {
                        maximum=presum[i][j];
                     }
                }
                
            }
            else 
            {
                presum[i][j]=(arr[i][j]+presum[i-1][j])+(presum[i][j-1]-presum[i-1][j-1]);
                
                if(presum[i][j]>maximum)
                     {
                        maximum=presum[i][j];
                     }
            }
        }
    }
    return maximum;
}
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cin>>n>>m>>q;
  arr=vector<vector<lli>>(n,vector<lli>(m,0));
  for(lli i=0;i<q;i++)
  {
    lli x1,y1,x2,y2,c;
    cin>>x1>>y1>>x2>>y2>>c;
    ans_to_query(x1,x2,y1,y2,c);
  }
 lli maximum= create_prefixsum();
 lli count=0;
  for(lli i=0;i<n;i++)
    {
        for(lli j=0;j<m;j++)
        {
            if(presum[i][j]==maximum)
            {
                count++;
            }
        }
    }
    cout<<maximum<<" "<<count;

  
}