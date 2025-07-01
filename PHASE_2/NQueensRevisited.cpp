#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
lli n,k;
vector<vector<pair<lli,lli>>> allsol;
vector<pair<lli,lli>> ans;
lli ct=0;
bool canplace(lli i,lli j){
    if(ans.empty()==true)
    return true;

    for(auto x:ans){
        if(x.first==i || x.second==j || abs(i-x.first)== abs(j-x.second) || (abs(i-x.first)==1 && abs(j-x.second)==2 )  ||(abs(i-x.first)==2 && abs(j-x.second)==1 )  )
        return false;
    }
    return true;
}
void rec(lli row){
    if(row>n)
    return;
    if(ans.size()>n){
        return;
    }
    if(ans.size()==n){
        ct++;
        allsol.push_back(ans);
        return;
    }
    
//rec(row+1); commenting this line because we need atleast 1 queen in 1 row, so we don't require recursive call with no queens on the row.
    for(lli i=0;i<n;i++){
        if(canplace(row,i)){
            ans.push_back({row,i});
            rec(row+1);
            ans.pop_back();
        }
    }    
    return;
    
}
signed main(){
     ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  
cin>>n>>k;

    rec(0);
    cout<<ct<<endl;
}