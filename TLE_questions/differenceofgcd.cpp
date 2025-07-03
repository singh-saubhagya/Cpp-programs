#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'


void solve(){
    lli n,l,r;
    cin>>n>>l>>r;
    vector<lli> arr;
    for(lli i=1;i<=n;i++)
    {
        lli val=((i+l-1))*i;
        if(val>r)
        {
            cout<<"NO"<<endl;
            return;
        }
        arr.push_back(val);
    }
    cout<<"YES"<<endl;
    for(auto x:arr)
    cout<<x<<" ";
    cout<<endl;
}
signed main(){
    lli t;
    cin>>t;
    while(t--)
    solve();
}