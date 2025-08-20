#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
const int inf=1e9;
void solve()
{
    string str;
    cin>>str;
    int n=str.length();
    int a=0;
    int b=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='a')
        a++;
        else b++;
    }
    int cura,curb;
    cura=0;
    curb=0;
    int ans=min(a,b);
    for(int i=0;i<n;i++)
    {
        if(str[i]=='a')
        cura++;
        else 
        curb++;
        ans=min(ans,curb+a-cura);
    }
    cout<<ans<<endl;
}
signed main()
{
  cin.tie(0); cout.tie(0);
  solve();
}