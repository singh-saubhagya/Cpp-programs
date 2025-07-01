#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
#define int long long

vector<lli> arr;
vector<lli> result;
bool check(int mid,int k)
{
    int sum=0;
    int size=arr.size();
    
    for(int i=0;i<size;i++)
    {
        sum=sum+arr[i];
        if(i+1<size && sum+arr[i+1]>mid)// to check whether alloted time don't exceeed the mid amount and if so then decrease the no of painter and start its time from sum =0!
        {
            sum=0;
            k--;
            if(k==0)
            {
                return 0;
            }
        }
        if(arr[i]>mid)
        {
            return 0;// in case the painter is alloted that board which takes more time than the mid
        }
        else if(i==size-1 && k>0)
        {
            if(arr[size-1]<=mid)
            {
                return 1;
                
            }
            else {
                return 0;
            }
            
        }      

    }
   
    if(k>=0) 
    return true;
    else 
    return false;

}
void solve()
 {
    int n,k;
    cin>>n>>k;
    int mintime=INT_MIN;
    int maxtime=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
        if(x>mintime)
        {
            mintime=x;
        }
        maxtime=maxtime+x;
    }
    int lo=0;
    int hi=maxtime;
    int mid;
    int ans;
    while(lo<=hi)
    {
        mid=lo+(hi-lo)/2;
        lli aa=check(mid,k);
       
        if(aa)
        {
            ans=mid;
            hi=mid-1;
        }
        else
        {
            lo=mid+1;
        }
    }
    result.push_back(ans);
 }
 signed main()
 {
   int q;
   ios_base::sync_with_stdio(0);
   cin.tie(0);cout.tie(0);
   cin>>q;
   
   while(q--)
   {
    solve();
    arr.clear();
   }
   for(lli i:result)
   {
    cout<<i<<endl;
   }
 }