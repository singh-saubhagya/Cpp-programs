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

for(auto x:ans)
{

    if(x.first==i || x.second==j || abs(i-x.first)==abs(j-x.second))
    {
        return 0;
    }
}
return 1;
}
void rec(lli row){
    if(row==n+1)
    return;
    if(ans.size()>k){
        return;
    }
    if(ans.size()==k){
        ct++;
        allsol.push_back(ans);
        return;
    }
    rec(row+1);

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