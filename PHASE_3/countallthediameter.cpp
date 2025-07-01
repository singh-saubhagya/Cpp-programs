#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &g, int node, vector<int>&vis, vector<int>&depth,vector<int>&parent){
    vis[node]=1;
    for(auto x:g[node]){
        if(vis[x]==0){
            parent[x]=node;
            depth[x]=depth[node]+1;
            dfs(g,x,vis,depth,parent);
        }
    }
}
vector<int> ans;
void countdiameter(vector<vector<int>>&g,vector<int>&vis, int pnt, int node , int dp, int &ln,int ld) 
{
    // dp is the current depth 
    // ln is the no of leaf nodes 
    // ld is length of diameter 
    // pnt is parent 

    int child=0;
    vis[node]=1;
    for(auto x:g[node])
    {
        if(x==pnt)
        continue;
        if(vis[x]==0)
        {
            child++;
            countdiameter(g,vis,node,x,dp+1,ln,ld);
            if(ln>0 && dp==0)// means the current node is the center . 
            {
                ans.push_back(ln);
                ln=0;
            }
        }
    }
    if(child==0 && dp==(ld/2))
    {
        ln++;
    }
}
signed main(){
    int n;
    cin>>n;
    vector<vector<int>> g;
    g.resize(n+1);
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> vis,depth,parent;
    vis.assign(n+1,0);
    depth.assign(n+1,0);
    parent.assign(n+1,0);
    dfs(g,1,vis,depth,parent);
    int de1;// one end of diameter
    int temp=INT_MIN;
    for(int i=1;i<=n;i++){
        if(depth[i]>temp){
            de1=i;
            temp=depth[i];
        }
    }
    vis.assign(n+1,0);
    depth.assign(n+1,0);
    parent.assign(n+1,0);
    dfs(g,de1,vis,depth,parent);
    int de2;
    temp=INT_MIN;
    for(int i=1;i<=n;i++)
    {
        if(depth[i]>temp){
            de2=i;
            temp=depth[i];
        }
    }
    int ld=temp;// length of diameter 
    temp=ld/2;
    int c1=de2;
    for(int i=1;i<=temp;i++){
        c1=parent[c1];
    }
    // for 2 center 
    int c2=parent[c1];
    cout<<c1<<" "<<c2<<endl;
    vis.assign(n+1,0);
    depth.assign(n+1,0);
    int pnt=c2;
    int ln=0;
    countdiameter(g,vis,pnt,c1,0,ln,ld);
    vis.assign(n+1,0);
    depth.assign(n+1,0);
    pnt=c1;
    ln=0;
    countdiameter(g,vis,pnt,c2,0,ln,ld);
    for(auto x:ans)
    cout<<x<<endl;
    int x=ans.size();
    vector<int> psum;
    psum.resize(x);
    int sum=0;
    for(int i=x-1;i>0;i--)
    {
        sum+=ans[i];
        psum[i]=sum;
    }
    int sol=0;
    for(int i=0;i<=x-2;i++)
    {
        sol+=ans[i]*psum[i+1];
    }
    cout<<sol<<endl;
}