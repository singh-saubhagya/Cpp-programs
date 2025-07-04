#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'

void solve(){
   lli n;
   cin>>n;
   map<lli,lli> m;
   for(lli  i=0;i<n;i++)
   {
        lli  x;
        cin>>x;
        m[x]++;
   }
   lli  ans=0;
   for(auto a:m)
   {
        for(lli  p=31;p>=1;p--)
        {
            lli val=(1LL<<p)-a.first;
           
            
                if(val>=a.first)
                {
                    if(m.find(val)!=m.end())
                    {
                    if(val==a.first)
                    {
                        lli  x=m[val];
                        ans+=x*(x-1)/2;
                    }
                    else 
                    {
                        ans+=m[val]*m[a.first];
                    }
                    }
                }
                
            
        }
   }
   cout<<ans<<endl;
}
signed main()
{
    lli t;
    cin>>t;
    while(t--)solve();
}