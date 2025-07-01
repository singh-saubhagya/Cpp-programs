#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
#define int long long

lli  m =INT_MAX;
lli  n=INT_MIN;
vector<lli> arr(1000000+2,0);
vector<lli> presum(1000000+2,0);
vector<lli> result;
vector<lli> good(1000000+2,0);
void solve()
 {

    lli l,r;
    cin>>l>>r;
    arr[l]++;
    arr[r+1]--;
 }
 void findprefixsum(int k)
 {
    lli sum=0;
    for(lli i=1;i<=1000000;i++)
    {
        sum=sum+arr[i];
        if(sum>=k)
        presum[i]=1;
        else
        presum[i]=0;
    }
    sum=0;
    for(lli i=1;i<=1000000;i++)
    {
        sum=sum+presum[i];
        good[i]=sum;
    }

 }
 void countstudent(lli k)
 {
    lli l,r;
    cin>>l>>r;
    result.push_back(good[r]-good[l-1]);
 }

 signed main()
 {
    lli q,n,k;

    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k>>q;
    lli query=q;
    
    while(n--)
    {
    solve();
    }
    findprefixsum(k);
    while(q--)
    {
    countstudent(k);

    }    
    
    for(lli i:result)
    {
        cout<<i<<endl;
    }
    
 }