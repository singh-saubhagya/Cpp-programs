#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define md 1000000007
void solve()
{
    lli n;
    cin>>n;
    vector<lli > a,b;
    for(lli  i=0;i<n;i++)
    {
        lli  x;cin>>x;a.push_back(x);
    }
    for(lli  i=0;i<n;i++)
    {
        lli  x;cin>>x;b.push_back(x);
    }

    sort(a.begin(),a.end());
    unordered_map<lli ,lli > m;
    for(lli  i=0;i<n;i++)
    {
        lli  val=b[i];
        auto it=upper_bound(a.begin(),a.end(),val);
        lli  temp=a.end()-it;
        m[b[i]]=temp;
       
    }
    sort(b.begin(),b.end());
    vector<lli > ans;
    reverse(b.begin(),b.end());
    for(lli  i=0;i<n;i++)
    {
       
        ans.push_back(m[b[i]]-i);
       
    }
    lli  sol=1;
    for(auto x:ans)
    {
        sol=sol%md*x%md;
        sol=sol%md;
    }
    cout<<sol<<endl;
}
signed main(){
    lli  t;
    cin>>t;
    while(t--)
    solve();
}