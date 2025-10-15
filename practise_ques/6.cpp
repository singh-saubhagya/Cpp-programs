#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
void solve()
{
    int n,k;
    cin>>n>>k;
    int no=n*n;
    int rem=n*n-k;
    if(rem==1)
    {
        cout<<"NO"<<endl;
        return; 
    }
    cout<<"YES"<<endl;
    int ct=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ct++;
            if(ct<=k)
            {
                cout<<"U";
            }
            else 
            {
                if(j==n-1 )
                {
                    if(i!=n-1)
                    cout<<"D";
                    else 
                    cout<<"L";
                }
                else
                {
                    cout<<"R";
                }
            }
        }
        cout<<endl;
    }
}
signed main()
{
  cin.tie(0); cout.tie(0);
  int t;cin>>t;while(t--)solve();
}