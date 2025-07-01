#include<bits/stdc++.h>
using namespace std;
void dfs(int node,int pnt,set<int> &temp,vector<vector<int>> &g,vector<int> &val)
{
    auto it=temp.lower_bound(val[node]);
    if(temp.size()>0)
    { 
    int a;
    if(it!=temp.end())
    {
         a=*it;
    }
   
    int b;
    it--;
    if(it!=temp.end())
    {
        b=*it;
    }
    int ans=min(abs(val[node]-b),abs(val[node]-a));  
    cout<<"Node : "<<node<<" evaluated to :"<<ans<<endl;
    }
    else 
    cout<<"Node : "<<node<<" has no ancestors i.e it is the root node "<<endl;
   
    for(auto x:g[node]){
        if(x!=pnt){
            temp.insert(val[node]);
            dfs(x,node,temp,g,val);
            temp.erase(val[node]);
        }
    }
}
signed main(){
    int n;
    cin>>n;
    vector<vector<int>> g;
    g.resize(n+1);
    vector<int> val;
    val.resize(n+1);
    for(int i=1;i<=n;i++)
    cin>>val[i];
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    set<int> temp;
    
    dfs(1,0,temp,g,val);
}