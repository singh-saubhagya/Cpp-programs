#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<vector<int>> &g,vector<int>&depth,int pnt)
{
    depth[node]=depth[pnt]+1;
    for(auto x:g[node]){
        if(x!=pnt){
            dfs(x,g,depth,node);
        }
    }
}
signed main()
{
    int n;
    cin>>n;
    vector<vector<int>> g;
    g.resize(n+1);
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> depth;
    depth.assign(n+1,-1);
    dfs(1,g,depth,0);// dfs(node,g,depth,pnt);
    vector<pair<int,int>> diameter;
    map<int,vector<int>> fends;

    for(int i=1;i<=n;i++)
    {
        fends[depth[i]].push_back(i);
    }
    auto it1 = fends.end();
    it1--;
    
    for(auto x:it1->second)
    {
      
        //x first end 
        depth.assign(n+1,-1);
        map<int,vector<int>> sends;
        dfs(x,g,depth,0);// dfs(node,g,depth,pnt);
        
        for(int i=1;i<=n;i++)
        {
            sends[depth[i]].push_back(i);
        }
        auto it2 = sends.end();
        it2--;
        for(auto y:it2->second)
        {
            diameter.push_back({x,y});
        }
    }
    for(auto x:diameter){
        cout<<"("<<x.first<<","<<x.second<<")"<<endl;
    }
}







