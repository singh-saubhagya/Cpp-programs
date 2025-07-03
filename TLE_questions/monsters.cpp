#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long lli;

signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        int k;
        cin>>n>>k;
        vector<int> arr(n+1);
        for(int i=1;i<=n;i++)
        cin>>arr[i];
        set<pair<int,int>> s;
        for(int i=1;i<=n;i++)
        {
            if(arr[i]%k==0)
            cout<<i<<" ";
            else 
            {
                s.insert({arr[i]%k,-i});
            }
        }
        for(auto it=s.rbegin();it!=s.rend();it++)
        {
            cout<<-it->second<<" ";
        }
        cout<<endl;
    }
}