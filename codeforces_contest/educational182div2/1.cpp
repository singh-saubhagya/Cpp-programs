#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
void solve()
{
    int n;
    cin>>n;
    vector<int> arr;
    arr.resize(n+2);
    for(int i=1;i<=n;i++)
    cin>>arr[i];
    vector<int> ps;
    ps.resize(n+2);
    ps[0]=0;
    int a,b;
    a=0;
    b=0;
    bool flag=false;
    for(int i=1;i<=n;i++)
    {
        ps[i]=ps[i-1]+arr[i];
    }
    for(int i=1;i<=n-2;i++)
    {
        for(int j=i+1;j<=n-1;j++)
        {
            int s1=ps[i];
            int s2=ps[j]-ps[i];
            int s3=ps[n]-ps[j];
            s1=s1%3;
            s2=s2%3;
            s3=s3%3;
            if(s1==s2)
            {
                if(s2==s3)
                {
                    flag=true;
                    a=i;
                    b=j;
                    break;
                }
            }
            else 
            {
                if(s1!=s3 && s3!=s2)
                {
                    flag=true;
                    a=i;
                    b=j;
                    break;
                }
            }
        }
        if(flag)
        break;
    }
    cout<<a<<" "<<b<<endl;
}
signed main()
{
  cin.tie(0); cout.tie(0);
  int t;cin>>t;while(t--)solve();
}