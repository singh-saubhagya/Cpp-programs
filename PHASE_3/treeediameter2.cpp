/*
The first input line contains an lli eger n: the number of nodes. The nodes are numbered 1, 2, …, n.
Then there are n − 1 lines describing the edges. Each line contains two lli egers a and b: there is an edge between nodes a and b.*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

typedef long long lli;vector<lli > temp;
void dfs(lli  node , lli  parent, vector<lli > &pnt, vector<vector<lli >> & g, vector<lli > &depth){
    depth[node]=depth[parent]+1;
    pnt[node]=parent;
    for(auto x:g[node])
    {
        if(x!=parent)
        {
            dfs(x,node,pnt,g,depth);
        }
    }
}
void nodeatdepth(lli  node, lli  parent ,vector<vector<lli >> &g,lli  depth, lli  dt,lli  &a,lli  &b,lli  center1)
{
    if(depth==(dt/2) && (g[node].size()==1))
    {
        a++;
    }
   
    for(auto x:g[node])
    {
        if(x!=parent)
        {
            nodeatdepth(x,node,g,depth+1,dt,a,b,center1);
            if(node==center1)
            {
                if(a>0)
                temp.push_back(a);
                a=0;
                }
            }
    }
    
}   
int  main()
{
    lli  n;
    cin>>n;
    vector<vector<lli >> g;
    g.resize(n+1);
    for(lli  i=1;i<=n-1;i++)
    {
        lli  a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }
    else if (n==2)
    
    {
        cout<<1<<endl;
        return 0;
    }
    vector<lli > pnt,depth;
    depth.assign(n+1,-1);
    pnt.resize(n+1);
    dfs(1,0,pnt,g,depth);
    lli  node1,dt1;
    dt1=-1;
    for(lli  i=1;i<=n;i++)
    {
        if(depth[i]>dt1)
        {
            node1=i;
            dt1=depth[i];
        }
    }
    depth.clear();
    depth.assign(n+1,-1);
    dfs(node1,0,pnt,g,depth);
    lli  node2,dt2;
    dt2=-1;
    for(lli  i=1;i<=n;i++)
    {
        if(depth[i]>dt2)
        {
            node2=i;
            dt2=depth[i];
        }
    }
    lli  dt=dt2;
    lli  center1=node2;
    for(lli  i=1;i<=(dt/2);i++)
    { 
        // cout<<node2<<endl;
        node2=pnt[node2];
        center1=node2;
       
    }
    //  cout<<center1<< " "<<dt<<endl;
    if(dt&1)
    {
        // diameter is odd length implies presence of two centers
        lli a,b;
        a=b=0;
        nodeatdepth(center1,pnt[center1],g,0,dt,a,b,center1);
        vector<int> temp2;
        for(auto x:temp)
        {
            temp2.push_back(x);
        }
        temp.clear();
        a=b=0;
        nodeatdepth(center1,0,g,0,dt+1,a,b,center1);
        int ans=0;
        for(auto x:temp)
        {
            for(auto y:temp2)
            ans+=x*y;
        }
        cout<<ans<<endl;
        return 0;
    }
    else 
    {
        lli a,b;
        a=b=0;
        nodeatdepth(center1,0,g,0,dt,a,b,center1);
    }
    // for(auto x:temp)
    // {
    //     cout<<x<<" ";
    // }
    lli  x=temp.size();
    vector<lli > psum;
    psum.resize(x);
    lli  sum=0;
    for(lli  i=x-1;i>0;i--)
    {
        sum+=temp[i];
        psum[i]=sum;
    }
    lli  ans=0;
    for(lli  i=0;i<=x-2;i++)
    {
        ans+=temp[i]*psum[i+1];
    }
    cout<<ans<<endl;

}