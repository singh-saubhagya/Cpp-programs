#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'

vector<lli> arr;
map<lli,lli> m;
lli n;
vector<lli> ans;
vector<vector<lli>> allsol;
void rec(lli level){
    if(level==n){
        allsol.push_back(ans);
        return;
    }
    for(auto v:m){
        if(v.second>0){
            ans.push_back(v.first);
            m[v.first]--;
            rec(level+1);
            ans.pop_back();
            m[v.first]++;
        }
    }

}
signed main(){
    cin>>n;
  
    for(lli i=0;i<n;i++){
    lli x;
    cin>>x;
    arr.push_back(x);
    m[x]++;
    }  
    rec(0);
    for(auto x:allsol){
        for(auto y:x)
        {
            cout<<y<<" ";
        }
        cout<<endl;
    }

}