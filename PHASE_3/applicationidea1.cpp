#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef long double ld;
vector<lli> caldivisors(lli n){
    vector<lli> div;
    for(lli  i=1;i*i<=n;i++)
    {
        if(i*i==n)
        {
            div.push_back(i);
            continue;
        }
        if(n%i==0)
        {
            div.push_back(i);
            div.push_back(n/i);
        }
    }
    return div;
}
lli poweroften(lli x)
{
    lli ans=1;
    for(lli i=1;i<=x;i++)
    {
        ans*=10;
    }
    return ans;
}
bool check(ld a, ld b , ld n)
{
    ld x=(a-n)*(b-n);
    if(x==(n*n))
    {
        return true;

    }
    return false;
}
signed main(){
    lli ct=0;
        for(lli  i=1;i<=2000;i++){
            lli n,d;
            cin>>n>>d;
            if(n==0 && d==0)
            {
                break;
            }

            vector<lli> div=caldivisors(n*n);
            ld m=n*n;
            for(auto x:div){
                //(b-n)(a-n)=n^2
                ld b=n+x;
                ld temp=m/x;
                temp=round(temp*poweroften(d));
                temp=temp/poweroften(d);
                cout<<x<<" "<<temp<<" "<<m<<endl;
                ld a=temp+n;
                bool flag=check(a,b,(ld)n);
                if(flag)
                ct++;
            }
            // cout<<ct<<endl;
        }
}