#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

signed main()
{
    string str;
    cin>>str;
    int n=str.length();
    vector<int> last,psum;
    last.assign(27,-1);
    psum.assign(n+1,0);
    int ps=1;
    int dp[1000];
    memset(dp,-1,sizeof(dp));
    
    for(int i=0;i<n;i++)
    {
        dp[i]=ps;

        if(last[str[i]-'a']!=-1)
        {
            int a=last[str[i]-'a'];
           
            if(a-1<0)
            {
                dp[i]--;
            }
            else 
            {
                 int b=psum[a-1];
                 dp[i]-=b;
            }
           
        }
        ps+=dp[i];
        psum[i]=ps;
        last[str[i]-'a']=i;
        
    }
    for(int i=0;i<n;i++)
    {
        cout<<dp[i]<<endl;
    }
}