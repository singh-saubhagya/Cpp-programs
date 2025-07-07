#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'

vector<lli>primes;

void solve(){
    lli n,m;
    cin>>n>>m;
    vector<lli> pr;
    for(lli i=2;i<=1e6;i++)
    {
        if(primes[i])
        {
            pr.push_back(i);
        
            if(pr.size()==m)
            {
                break;
            }
        }
    }

    lli nn=n;
    lli ans=0;
    while(nn!=0)
    {
        auto it=lower_bound(pr.begin(),pr.end(),nn);
        if(it!=pr.end() && *it==nn)
        {
            ans++;
            break;
        }
        else 
        {
            it--;
            lli x=nn%(*it);
            if(x==1)
            {
                x+=*it;
                ans=ans+(nn/(*it))-1;
                pr.erase(it);
            }
            else
            {
                ans=ans+(nn/(*it));
            }
            nn=x;
        }
    }
    cout<<ans<<endl;

    
}
signed main(){
    primes.assign(1e6+2,1);
    primes[0]=0;
    primes[1]=0;
    for(lli i=2;i<=1e6;i++)
    {
        if(primes[i])
        {
            for(lli j=i*i;j<=1e6;j+=i)
            {
                primes[j]=0;
            }
        }
    }

    solve();
}