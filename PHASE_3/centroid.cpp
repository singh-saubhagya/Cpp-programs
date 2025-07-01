#include<bits/stdc++.h>
using namespace std;
void dfs(int node , int pnt , vector<int> &st,vector<vector<int>> &g,int n,int centroid)
{
    st[node]=1;
    bool flag=false;
    
    for(auto x:g[node])// visiting all the child of node 
    {
        if(x!=pnt){
            dfs(x,node,st,g,n,centroid);
            st[node]+=st[x];
            if(st[x]>ceil(n/2) && node == centroid)
            {
                // node : it represents at which node we are.
                // centroid : it stores the valuse of the centroid we have assumed.
                // x : represents the child of node , 
                // node == centroid, this condn check whether are we at centroid or not , if we are at assumed centroid , then if any the subtree of centroid has > n/2 nodes then , our new centroid will chagne to that child , x here .   
                st.assign(n+1,0);
                dfs(x,node,st,g,n,x);
                flag=true;
                
            }
            if(flag==true)// pruning if one of the child of current centroid node  has size > n/2 , then the answer lies inside this child subtree, therfore their no need to visit the other child of currrent Centroid node as ther subtree will sure be less than n/2
            return;
        }
    }
    if(node == centroid && flag==false)// all the child of centroid has < n/2 nodes 
    {
        cout<<centroid<<endl;
    }
}
signed main(){
    int n;
    cin>>n;
    vector<vector<int>> g;
    g.resize(n+1);  
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> st;// subtree;
    st.assign(n+1,0);
    dfs(1,0,st,g,n,1);
}