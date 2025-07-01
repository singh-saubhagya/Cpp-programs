#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
lli findpower(lli a,lli b){
    if(b==0)
    return 1;
    if(a==0)
    return 0;
    if((b&1)==0)
    {
        lli x=findpower(a,b/2);
        return x*x;

    }
    else{
        lli x=findpower(a,b-1);
        return a*x;
    }
}
void rec(int a,vector<vector<pair<lli,lli>>> &temp, int b,vector<lli> &pf){
    if(pf[a]==a)
    {
        if(temp[b].empty()==false)
        {
        auto it=temp[b].rbegin();
        if( a==it->first )
        {
            it->second++;
        }
        else 
        {
            temp[b].push_back({a,1});
        }  
        }
        else 
        {
            temp[b].push_back({a,1});
        }
        
    }
    else {
        lli x=pf[a];
        
        if(temp[b].empty()==false)
        {
                auto it=temp[b].rbegin();
                if(x==it->first)
                {
                    it->second++;
                }
                else 
                {
                    temp[b].push_back({x,1});
                }
        }
        else 
        {
            temp[b].push_back({x,1});
        }
        
         rec(a/pf[a],temp,b,pf);
    }
    return;
}
signed main(){
    lli n;
    cin>>n;
    vector<lli> arr;
    arr.resize(n);
    lli x=LLONG_MIN;
    for(lli i=0;i<n;i++)
    {cin>>arr[i];
    x=max(arr[i],x);}
    
    vector<lli> pf;//prime factors
    pf.resize(x+1);
    for(lli i=1;i<=x;i++){
        pf[i]=i;
    }
    for(lli i=2;i<=x;i++){
        if(pf[i]==i){
            for(lli j=i*i;j<=x;j+=i){
                if(pf[j]==j){
                    pf[j]=i;
                }
            }
        }
    }
    
    vector<vector<pair<lli,lli>>> temp;
    temp.resize(n);
    for(lli i=0;i<n;i++){
        rec(arr[i],temp,i,pf);
    }
    // for(lli i=0;i<n;i++)
    // {
    //     vector<pair<lli,lli>> ans=temp[i];
    //     for(auto x:ans)
    //     {
    //         cout<<"("<<x.first<<","<<x.second<<")"<<"  ";
    //     }
    //     cout<<endl;
    // }
    map<lli,lli> m;
    lli res=0;
    for(lli i=0;i<n;i++){
        vector<pair<lli,lli>> ans=temp[i];
        lli tar=1;
        lli nor=1;
        for(auto x:ans)
        {
          lli a,b;
          a=x.first;
          b=x.second;
          b=x.second%3;
          nor*=findpower(a,b);
          
          if(b!=0)
          {
            b=3-b;
            tar*=findpower(a,b);
          }
          
        }
        res+=m[tar];
      
        m[nor]++;
    
    }
    
    cout<<res<<endl;
}