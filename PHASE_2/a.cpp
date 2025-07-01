#include<bits/stdc++.h>
#include<math.h>
using namespace std;
typedef long long lli;
#define tab '\t'
#define endl '\n'

lli k,x;
lli ctbits(lli mid){
    if(mid==0)
    return 0;
    lli ct=0;
    while(mid!=0){
        ct++;
        mid=mid>>1;
    }
    return ct;
}
lli findpower(lli a,lli b){
    if(b==0)
    return 1;
    if(a==0)
    return 0;

    lli ans=1;
    if(b&1)
    ans=findpower(a,b-1)*a;
    else
    {
        lli x=findpower(a,b/2);
        ans=x*x;
    }
    return ans;
}
bool check(lli mid){

    lli cnt=ctbits(mid);
     cout<<"cnt"<<tab<<cnt<<endl;
    lli ct=0;
    for(lli i=0;i<cnt;i++){
        if(ct>k)
        return 0;
        if((i+1)%x==0)
        {
            lli a=(mid+1)/findpower(2,i+1);
            if(a>k)
            return 0;
            ct+=a*findpower(2,i);
            if(ct>k)
            return 0;
            lli b=(mid+1)%findpower(2,i+1);
            
            ct+=max(b-findpower(2,i),0LL);
            if(ct>k)
            return 0;
            
        }
    }
     cout<<"ct"<<tab<<ct<<endl;
    return 1;
}
signed main()
{
    cin>>k>>x;
    lli lo=0;
    lli hi=LLONG_MAX;
    lli ans;
    while(lo<=hi){
        lli mid=lo+(hi-lo)/2;
        if(check(mid))
        {
             cout<<"mid"<<tab<<mid<<endl;
            ans=mid;
            lo=mid+1;
        }
        else
        {
            hi=mid-1;
        }
    }
    cout<<ans<<endl;
}