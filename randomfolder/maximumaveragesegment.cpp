#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
using ld =long double;
vector<lli> arr;
lli n,d;
pair<lli,lli> p;
bool exist(vector<ld>  x)
{
    // our goal in this function is to find the subarray having sum >=0 
    // subarray sum from l to r is given as x[r]-(l==0?0:x[l-1])
    // to find the maximum sum we need to minimize the x[l-1] therefore using minindex which stores the minindex in the range (0 to l-1 if l>0) and -1 if l==0
    ld ans;
    lli minindex;    
    for(lli r=d-1;r<n;r++)
    {
        lli l=r-(d-1);// finding maximum l possible for each r  
        lli z=l-1;//  now reducing it by 1 because if we want sum of subarray from l to r we want l-1 !
        if(z==-1)// implies l=0; 
        {
            ans=x[r]-0;
            if(ans>0)// mean exist 
            {
                p.first=0;
                p.second=r;
                return true;
            }
            minindex=-1;// storing minindex  in the range of all possible l for each r 
        }
        else
        {
            if(x[z]<(minindex==-1?0:x[minindex]))// the z here can have minimum value than at minindex so we are updating minindex accordingly
            {                                    // 
                minindex=z;
            }
            ans=x[r]-(minindex==-1?0:x[minindex]);
            if(ans>0)
            {
                    p.first=minindex+1;
                    p.second=r;
                    return true;
                    
            }
            
        }

    }
    if(ans>0)
    {
        return true;
    }
    else 
    return false;
}
bool check(ld mid)
{
    vector <ld> x;
    ld sum=0;
    for(lli i=0;i<n;i++ )
    {
        x.push_back(arr[i]-mid);// subtracting mean 
        sum+=x[i];
        x[i]=sum;// making prefix sum
    }
    bool flag=exist(x);
    return flag;
}
void solve()
{
    lli maxavg;
    cin>>n>>d;
    ld lo=INT_MAX,hi=INT_MIN;
    for(lli i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
        if(x<lo)
        {
            lo=x;
        }
        if(x>hi)
        {
            hi=x;
        }

    }
    if(d==1 && n==1)
    {
        maxavg=arr[0];
        return ;
    }
    ld ans;
    ld mid;
    pair <lli,lli> result;
    for(int i=0;i<40;i++) // finding mean on real domain as on integer domain will create precison issues
    {
        mid=lo+(hi-lo)/2;
        
        if(check(mid)==1)
        {
            ans=mid;
            lo=mid;
            result=p;
        }
        else 
        hi=mid;
    }
    cout<<p.first+1<<tab<<p.second+1;

}
signed main()
{
  
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cout<<endl;
  solve();
  

}