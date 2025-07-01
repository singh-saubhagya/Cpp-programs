#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
#define int long long
vector<lli> arr;
vector<lli> presum;
vector<lli> result;
bool check(int mid,int k)
{
    int x;
    for(int st=0;st<arr.size();st++)
    {
    //   cout<<endl<<"st"<<tab<<st<<endl;

        int end=st+mid-1;
        if(end<=arr.size()-1)
        {
            if(st==0)
            {
                x=mid-presum[end];
                // cout<<endl<<"x"<<tab<<x<<endl;
                if(x<=k)
                return true;
            }
            else
            {
                x=mid-presum[end]+ presum[st-1];
                // cout<<endl<<"x"<<tab<<x<<endl;

                if(x<=k)
                return true;   
            }
        }
        else
        return false;
    }
    return false;
}
void solve()
 {
    int n,k,count=0,c=0;
    cin>>n>>k;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
        if(x)
        {
            count++;
        }
        else
        {
            if(count>c)
            {
                c=count;
            }
            count=0;
        }
        sum+=x;
        presum.push_back(sum);
    }
    int ans, lo=c,hi=n,mid;
    while(lo<=hi)
    {
        mid=lo+(hi-lo)/2;
        // cout<<endl<<"mid"<<tab<<mid<<endl;
        if(check(mid,k)==1)
        {
            ans=mid;
            lo=mid+1;
        }
        else
        
        hi=mid-1;
    }
    result.push_back(ans);
 }
 signed main()
 {
   int q;
   ios_base::sync_with_stdio(0);
   cin.tie(0);cout.tie(0);
   cin>>q;
   cout<<endl;

   while(q--)
   {
    solve();
    arr.clear();
    presum.clear();
   }
   for(int i:result)
   {
        cout<<i<<endl;
   }

 }