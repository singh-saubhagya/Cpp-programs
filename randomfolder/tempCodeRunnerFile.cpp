#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
#define int long long

vector<lli> arr(1000000+2,0);
vector<lli> presum(1000000+2,0);
vector<pair<lli,lli>> query;
vector<lli> result;
void solve(lli max,lli min)
 {

    lli l,r;
    cin>>l>>r;
    arr[l]++;
    arr[r+1]--;
    if(l<min)
    {
        min=l;
    }
    if(r>max)
    {
        max=r;
    }
 }
 void findprefixsum(lli max,lli min)
 {
    lli sum=0;
    for(lli i=min;i<=max;i++)
    {
        sum=sum+arr[i];
        presum[i]=sum;
    }
 }
 void countstudent(lli k)
 {
    lli l,r;
    cin>>l>>r;
    lli count=0;
    for(lli i=l;i<=r;i++)
    {
        if(presum[i]>=k)
        {
            count++;
        }
    }
    result.push_back(count);
 }

 signed main()
 {
    lli q,n,k;

    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k>>q;
    lli query=q;
    lli max=INT_MIN;
    lli min=INT_MAX;
    while(n--)
    {
    solve(max,min);
    }
    findprefixsum(max,min);
    while(q--)
    {
    countstudent(k);

    }    
    
    for(lli i=0;i<query;i++)
    {
        cout<<result[i]<<endl;
    }

 }