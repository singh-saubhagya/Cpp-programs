
#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
lli  dp[64][64][3];
lli  n;
lli  sb;
vector<lli > binofn;
lli  l;
void findbin(lli  x)
{
  
    while(x)
    {
        lli  y=x%2;
        binofn.push_back(y);
        x=x/2;
    }
    l=binofn.size();
    reverse(binofn.begin(),binofn.end());
}
int rec(int pos, int setbits, int tight) {
    if (setbits > sb) return 0;
    if (pos == l) return setbits == sb;

    if (dp[pos][setbits][tight] != -1)
        return dp[pos][setbits][tight];

    int limit = (tight == 1) ? binofn[pos] : 1;
    int ans = 0;

    for (int i = 0; i <= limit; i++) {
        int newTight = (tight == 1 && i == limit) ? 1 : 0;
        ans += rec(pos + 1, setbits + i, newTight);
    }

    return dp[pos][setbits][tight] = ans;
}

lli countbits(int x)
{
    int ct=0;
    while(x!=0)
    {
        x=x/2;ct++;
    }
    return ct;
}
    
long long popcountDepth(long long nn, lli  k) {
        lli  dep[55];
        dep[1]=0;
        n=nn;
        if(k==0)return 1 ;
        findbin(n);
        for(lli  i=2;i<=53;i++)
        {
         lli x = __builtin_popcountll(i);
            lli  val=1+dep[x];
            dep[i]=val;
        }
        lli  ans=0;
        for(lli  i=1;i<=53;i++)
        {
            if(dep[i]==k-1)
            {
                sb=i;
                memset(dp,-1,sizeof(dp));
                ans+=rec(0,0,1);
            }
        }
        if(k==1)
        ans--;
        return ans;
    }

    signed main()
    {
        int a,b;
        cin>>a>>b;
        cout<<popcountDepth(a,b);
    }
