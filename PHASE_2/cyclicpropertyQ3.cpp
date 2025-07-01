#include<bits/stdc++.h>
#include<math.h>
using namespace std;
typedef long long lli;
#define tab '\t'
#define endl '\n'

lli findpower(lli a,lli b)
{
        if(a==0)
        return 0;
        if(b==0)
        return 1;
        
        if(b%2==0){
          return  findpower(a,b/2) * findpower(a,b/2);
        }
        else
        return  a* findpower(a,b-1);

}
lli ctbits(lli x){
    lli ct=0;
    if(x==0)
    return 1;

    while(x!=0){
        ct++;
        x=x>>1;
    }  

    return ct;
}

lli no_of_1(lli mid)
{
    
    lli cnt=ctbits(mid);
   
    lli no=0;
    for(lli i=0;i<cnt;i++){
        lli a=(mid+1)/findpower(2,i+1);
        lli b=findpower(2,i)*a;
        lli c=(mid+1)%findpower(2,i+1);
        c=max((c-findpower(2,i)),0LL);
        no+=b+c;
    } 
    return no;
}

bool check(lli mid,lli x){
   
    lli cnt=ctbits(mid);
   
    lli no=0;
    for(lli i=0;i<cnt;i++){
        lli a=(mid+1)/findpower(2,i+1);
        lli b=findpower(2,i)*a;
        lli c=(mid+1)%findpower(2,i+1);
        c=max((c-findpower(2,i)),0LL);
        no+=b+c;
    } 

           
    // cout<<"mid"<<tab<<mid<<tab<<"cnt"<<tab<<cnt<<endl;
    // cout<<"no"<<tab<<no<<endl;
    if(no>=x)
    return 1;
    else
    return 0;
}
string printbit(lli x)
{
    string str="";
    if(x==0)
    return "0";
    while(x!=0)
    {
        lli b=x&1;
        str+=(b?"1":"0");
        x=x>>1;
    }
    reverse(str.begin(),str.end());
    return str;
}
void enigma(lli x){
    lli lo=0;
    lli hi=1e9;
    lli ans;
    while(lo<=hi){
        lli mid=lo+(hi-lo)/2;
        if(check(mid,x)){
            ans=mid;
            hi=mid-1;
        }
        else
        {
            lo=mid+1;
        }
    }
    lli a=no_of_1(ans-1);
    lli b=0;
    for(lli i=0;i<=ans-1;i++)
    {
        b+=ctbits(i);
    }
    lli left=x-a;
    string str=printbit(ans);
    // cout<<'a'<<tab<<a<<tab<<'b'<<tab<<b<<endl;
    // cout<<str;
    for(lli i=0;i<str.length();i++)
    {
        if(str[i]=='1')
        {
            left--;
        }
        if(left==0)
        {
           cout<< b+i<<endl;
           break;
        }
    }
    

}
signed main(){
    lli q;
    cin>>q;
    for(lli i=0;i<q;i++){
        lli x;cin>>x;enigma(x);
    }

}