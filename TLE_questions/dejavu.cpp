#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
void solve(){
    lli n,q;
    cin>>n>>q;
    vector<lli> a,x;
    a.resize(n);
    x.resize(q);
    for(lli  i=0;i<n;i++)
    cin>>a[i];
    for(lli  i=0;i<q;i++)
    cin>>x[i];
    vector<lli> temp=a;
    vector<vector<lli>> cal;
    cal.resize(35);
    vector<bool> flag;
    flag.assign(n,true);
    for(lli  i=31;i>=1;i--)
    {
        lli val=1LL<<i;
        for(lli  j=0;j<n;j++)
        {
            if(flag[j] && a[j]%val==0)
            {
                cal[i].push_back(j);
                flag[j]=false;
            }
        }
    }

    for(lli i=0;i<q;i++)
    {
       
        for(lli k=x[i];k<=31;k++)
        {
            for(lli j:cal[k])
            {
          
            a[j]+=(1LL<<(x[i]-1));
            cal[x[i]-1].push_back(j);
            }
           
            cal[k].clear();
        }
        
        
    }
    for(auto x:a)
    cout<<x<<" ";
    cout<<endl;
}
signed main()
{
    lli t;
    cin>>t;
    while(t--)solve();
}