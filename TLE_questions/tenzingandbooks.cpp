#include<bits/stdc++.h>
using namespace std;

typedef long long lli;
#define endl '\n'
void solve(){
    lli n,x;
    cin>>n>>x;
    vector<lli> arr;
    arr.resize(3*n+2);
    for(int i=1;i<=3*n;i++)
    {
        cin>>arr[i];
    }
    lli target=0;
    for(int i=1;i<=n;i++)
    {
        lli val=arr[i];
        bool flag=true;
        for(lli i=0;i<=32;i++)
        {
            if(((x>>i)&1LL) == 0 && ((val>>i)&1LL) == 1 )
            {
                flag=false;// can't take or with this no
            }
        }
        if(flag)
        {
            target=target|val;
        }
        else 
        break;
    }
    for(int i=n+1;i<=2*n;i++)
    {
        lli val=arr[i];
        bool flag=true;
        for(lli i=0;i<=32;i++)
        {
            if(((x>>i)&1LL) == 0 && ((val>>i)&1LL) == 1 )
            {
                flag=false;// can't take or with this no
            }
        }
        if(flag)
        {
            target=target|val;
        }
        else 
        break;
    }
    for(int i=2*n+1;i<=3*n;i++)
    {
        lli val=arr[i];
        bool flag=true;
        for(lli i=0;i<=32;i++)
        {
            if(((x>>i)&1LL) == 0 && ((val>>i)&1LL) == 1 )
            {
                flag=false;// can't take or with this no
            }
        }
        if(flag)
        {
            target=target|val;
        }
        else 
        break;
    }
    if(target == x)
    cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
}
signed main()
{
    lli t;
    cin>>t;
    while(t--)
    solve();
}