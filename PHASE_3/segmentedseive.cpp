#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
 
signed main(){
    lli l,r;
    cin>>l>>r;
    lli n=sqrt(r)+1;
    vector<bool> arr;
    arr.assign(n+1,true);
    vector<lli> primes;
    for(lli i=2;i<=n;i++){
        if(arr[i]){
            for(lli j=i*i;j<=n;j+=i){
                arr[j]=false;
            }
            primes.push_back(i);
        }
    }
    vector<bool> ans;
    ans.assign(r-l+2,true);
    for(auto x:primes){
        lli temp=ceil(l/x)*x;
        temp=max(x*x,temp);
        while (temp <= r) {
            if (temp != x && (temp - l) >= 0 && (temp - l) < ans.size()) {// also check for valid index , if you are performing operation on index of array
                ans[temp - l] = false;
            }
            temp += x;
        }
    }
    lli ct=0;
    for(int j=0;j<r-l+1;j++)
    {
        if(ans[j] && j+l != 1)
        ct++;
    }
    cout<<ct<<endl;
    for(int j=0;j<r-l+1;j++)
    {
        if(ans[j] && j+l != 1)
        cout<<j+l<<" ";
    }
    
}