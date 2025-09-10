#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
const int inf = 1e9;
 vector<int> maxValue(vector<int>& nums) {
       int n=nums.size();
        vector<int> a,b;
        a.resize(n);
        b.resize(n);
        vector<pair<int,int>> temp;
        for(int i=0;i<n;i++)
        {
            temp.push_back({nums[i],i});
        }
        int smlid=-inf;
        sort(temp.begin(),temp.end());

        for(auto x:temp)
        {
            int val=x.first;
            int id=x.second;
            smlid=max(id,smlid);
            a[id]=smlid;
        }
        
        int larid=0;
            b[0]=0;
        for(int i=1;i<n;i++)
            {
                if(nums[larid]<=nums[i])
                {
                    larid=i;
                    b[i]=i;
                }
                else 
                {
                    b[i]=larid;
                }
            }
        vector<int> ans;
        ans.resize(n);
        for(int i=0;i<n;i++)
            {
                int val1=nums[b[a[i]]];
                int val2=nums[b[i]];
                ans[i]=max(val1,val2);
            }
            for(auto x:a)
            {
                cout<<x<< " ";
            }
            cout<<endl;
            for(auto y:b)
            {
                cout<<y<<" ";
            }
            cout<<endl;
        return ans;
    }
signed main()
{
  cin.tie(0); cout.tie(0);
  int n=5;

  vector<int> arr={30,21,5,35,24};
  
  vector<int> ans=maxValue(arr);
  cout<<endl;
  for(auto x:ans)
  {
    cout<<x<<" ";
  }

}
   