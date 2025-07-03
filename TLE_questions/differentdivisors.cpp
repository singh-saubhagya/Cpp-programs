#include<bits/stdc++.h>
using namespace std;

typedef long long lli;
#define endl '\n'

vector<lli > arr;// d=1e4
vector<lli > primes;
void solve()
{
    lli  d;
    cin>>d;
    lli  a;
    lli  target =1+d;
    auto it=lower_bound(primes.begin(),primes.end(),target);
    a=*it;
    target=*it+d;
    it=lower_bound(primes.begin(),primes.end(),target);
    a=a*(*it);
    cout<<a<<endl;
}
signed main()
{
    lli  t;
    cin>>t;
    arr.assign(1e5+2,1);
    arr[1]=0;
    for(lli  i=2;i<1e5;i++)
    {
        if(arr[i])
        {
            for(lli  j=i*i;j<1e5;j+=i)
            {
                arr[j]=0;
            }
            primes.push_back(i);
        }
    }
   
    while(t--)
    {solve();}
}