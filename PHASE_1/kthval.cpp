#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'


struct query{
    lli n,m,q;
    vector<lli> arr;
    vector<lli> s;
    lli l,r;
   vector<lli> initialize()
    {
        cin>>n>>m>>q;
        s=vector<lli>(n,0);
        vector<lli> result;
        for(lli i=0;i<n;i++)
        {
            lli x;
            cin>>x;
            arr.push_back(x);

        }
        for(lli i=0;i<m;i++)
        {
            cin>>l>>r;
            l--;
            r--;
            s[l]+=1;
            if(r+1<n)
            s[r+1]-=1;

        }
        
        for(lli i=1;i<n;i++)
        {
            s[i]=s[i]+s[i-1];
        }
        // for(lli i=0;i<n;i++)
        // {
            
        //         while(s[i])
        //         {
        //             temp.push_back(arr[i]);//this causes runtime error as in worst case will create an array of n*q 
        //             s[i]--;
        //         }
               
            
        // }
        vector<pair<lli,lli>> temp;
        for(lli i=0;i<n;i++)
        {
            if(s[i]>0)
            {
                temp.push_back({arr[i],s[i]});
            }
        }
        sort(temp.begin(),temp.end());
        for(lli i=1;i<temp.size();i++)
        {
           
           temp[i].second=temp[i].second+temp[i-1].second;
        }
        vector<lli> v;
        for(lli i=0;i<temp.size();i++)
        {
           v.push_back(temp[i].second);
        }
        while(q--)
        {
            lli z;
            cin>>z;
            lli pn=lower_bound(v.begin(),v.end(),z)-v.begin();
            if(pn>temp.size()-1)
            {
                result.push_back(-1);
            }
            else{
                result.push_back(temp[pn].first);
            }
        }
         return result;
         
       


    }
};
signed main()
{
  lli t;
  cin>>t;
  vector<vector<lli>> ans;
 
  lli j=0;
  while(t--)
  {
    query x;

    ans.push_back(x.initialize());


  }
  for(vector<lli> v:ans)
  {
    for(lli x:v)
    {
        cout<<x<<" ";
    }
    cout<<endl;
  }


}