#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
void solve()
{
    int n,k;
    cin>>n>>k;
    string str;cin>>str;
    vector<int> arr;
    arr.resize(n+3);
    int ct=0;
    for(int i=0;i<n;i++)
    {
        arr[i]=str[i]-'0';
        // consecutive 1 check. 
        if(arr[i])
        {
            ct++;
            if(ct>=k)
            {
                cout<<"NO"<<endl;
                return;

            }
        }
        else 
        ct=0;
    }
    cout<<"YES"<<endl;
    int num=n;
    vector<int> ans;
    ans.resize(n+2);
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            ans[i]=num;
            num--;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1)
        {
            ans[i]=num;
            num--;
        }
    }
    for(int i=0;i<n;i++)
    cout<<ans[i]<<" ";
    cout<<endl;
}
signed main()
{
  cin.tie(0); cout.tie(0);
  int t;
  cin>>t;
  while(t--)
  solve();
}