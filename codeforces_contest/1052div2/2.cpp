#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
void solve()
{
    lli n,m;
    cin>>n>>m;
    vector<vector<lli>> arr;
    vector<lli> freq;
    freq.resize(m+2);
    for(lli i=0;i<n;i++)
    {
        lli l;
        cin>>l;
        vector<lli> temp;
        for(lli j=0;j<l;j++)
        {
            lli x;
            cin>>x;
            temp.push_back(x);
            freq[x]++;
        }
        arr.push_back(temp);
    }
    for(lli i=1;i<=m;i++)
    {
        if(freq[i]==0)
        {
            cout<<"NO"<<endl;return;
        }
    }
    lli ct=0;
    for(int i=0;i<n;i++)
    {
        bool flag=true;
        for(auto x:arr[i])
        {
            if(freq[x]<2)
            {
                flag=false;
                break;
            }
        }
        if(flag)
        ct++;
    }
    if(ct>=2)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
}
signed main()
{
  cin.tie(0); cout.tie(0);
  lli t;cin>>t;while(t--)solve();
}