#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'

void solve()
{
    int q;
    cin>>q;
    vector<int> arr;
    while(q--)
    {
        string que;
        cin>>que;
        int x;
        cin>>x;
        if(que=="add")
        {
                  
           auto pre=lower_bound(arr.begin(),arr.end(),x);
           if(pre!=arr.end() && *pre==x)
           continue;
           auto it = upper_bound(arr.begin(),arr.end(),x);
     
           if(it==arr.end())
           {
            arr.push_back(x);
           }
           else 
           {
            arr.insert(it,x);
           }
    
        }
        else if (que=="remove")
        {
          auto pre=lower_bound(arr.begin(),arr.end(),x);
          if(pre==arr.end() )
          continue;
          if(*pre!=x)
          continue;
          
          arr.erase(pre);
        }
        else if (que=="find")
        {
          int sz=arr.size();
          if(x>=0 && x<=sz-1)
          {
            cout<<arr[x]<<endl;
          }
          else 
          {
            cout<<-1<<endl;
          }
        }
        else if(que=="findpos")
        {
          auto pre=lower_bound(arr.begin(),arr.end(),x);
          cout<<pre-arr.begin()<<endl;
        }
    }
}
signed main()
{
  cin.tie(0); cout.tie(0);
  int t;cin>>t;while(t--)solve();
}