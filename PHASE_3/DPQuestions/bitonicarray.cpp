#include<bits/stdc++.h>
using namespace std;

vector<int> lis(int n, vector<int> &arr)
{
    vector<int> len,ans;
    for(int i=0;i<n;i++)
    {
        if(ans.size()==0 || ans.back()<arr[i])
        {
            ans.push_back(arr[i]);
            len.push_back(ans.size());
        }
        else
        {
            auto it=lower_bound(ans.begin(),ans.end(),arr[i]);
            *it=arr[i];
            len.push_back(it-ans.begin()+1);
        }

    }
    return len;
}
signed main()
{
    int n;vector<int>arr;
    cin>>n;arr.resize(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    vector<int> a=lis(n,arr);
    reverse(arr.begin(),arr.end());
    vector<int> b=lis(n,arr);
    reverse(b.begin(),b.end());
    int ans=-1;
    for(int i=0;i<n;i++)
    {
     cout<<"idx :"<<i<<endl;   cout<<a[i]<<" "<<b[i]<<endl;
        ans=max(ans,a[i]+b[i]);
    }
    cout<<ans<<endl;
}