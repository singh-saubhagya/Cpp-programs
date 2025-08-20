#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
signed main()
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;arr.push_back(x);
    }

    vector<int> ans,len;
    // in the len array we are storing which element is inserted at which length,
    for(int i=0;i<n;i++)
    {
        if(ans.size()==0 || ans.back()<arr[i])
        {
            ans.push_back(arr[i]);
            int sz=ans.size();
            len.push_back(sz);
        }
        else 
        {
            auto it=lower_bound(ans.begin(),ans.end(),arr[i]);
            *it=arr[i];
            len.push_back(it-ans.begin()+1);
        }
    }   
    
    int cl=ans.size();
    vector<int> sol;
    for(int i=n-1;i>=0;i--)
    {
        if(len[i]==cl)
        {
            sol.push_back(arr[i]);
            cl--;
            if(cl==0)
            break;
        }
    }
    for(auto x:sol)
    cout<<x<<" ";

}