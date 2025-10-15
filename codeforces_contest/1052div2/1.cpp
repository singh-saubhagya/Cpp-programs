#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
void solve()
{
    lli n;
    cin>>n;
    vector<int> arr;
    arr.resize(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];

    map<int,int> freq;
    for(int i=0;i<n;i++)
    {
        freq[arr[i]]++;
    }
    vector<int> temp;
    for(auto x:freq)
    {
        int ct=x.second;
        temp.push_back(ct);
    }
    sort(temp.begin(),temp.end());
    int nn=temp.size();
    int fa=INT_MIN;
    for(int i=0;i<nn;i++)
    {
        int cur=temp[i];
        int len=nn-i;
        int ans=len*cur;
        fa=max(fa,ans);
    }
    cout<<fa<<endl;
}
signed main()
{
  cin.tie(0); cout.tie(0);
  int t;
  cin>>t;while(t--) solve();
}