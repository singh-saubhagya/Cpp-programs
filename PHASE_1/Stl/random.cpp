#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
void solve()
{

int num=5;
                int val=0;
                for(int j=0;j<=30;j++)
                    {
                        if(((num>>j)&1LL)==0)
                        {
                            val=(1LL<<j)|val;
                            cout<<val<<endl;
                        }
                    }
                    cout<<val<<endl;
                
            
}
signed main()
{
  cin.tie(0); cout.tie(0);
  solve();
}