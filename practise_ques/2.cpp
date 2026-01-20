 
  #include<bits/stdc++.h>
 using namespace std;
 typedef long long lli;
 #define endl '\n'
 #define tab '\t'
         vector<vector<int>> g;
         vector<int> pnt,val,vis;
         vector<int> order;
         void dfs(int node ,int p)
         {
            vis[node]=1;
            pnt[node]=p;
            for(auto x:g[node])
            {
                if(vis[x]==0)
                {
                    dfs(x,node);
                }
                else if(vis[x]==1 && x!=p)
                {
                    
                     val[pnt[x]]--;
                     val[node]++;
                      
                }
            }
            vis[node]=2;
            order.push_back(node);
            return ; 
         }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
         g.resize(n+1);
         for(auto x: connections)
         {
            int a=x[0];
            int b=x[1];
            g[a].push_back(b);
            g[b].push_back(a);
         }
         pnt.resize(n+1);
         val.assign(n+1,0);
         vis.assign(n+1,0);
         pnt[0]=n;
         dfs(0,n);
         for(int i=0;i<n;i++)
         cout<<i<<" "<<val[i]<<endl;
         for(auto x:order)
         {
             
            val[pnt[x]]+=val[x];
            
         }
         
         cout<<endl;
         
         for(int i=0;i<n;i++)
         cout<<i<<" "<<pnt[i]<<" " << val[i]<<" "<<endl;
         cout<<endl;
         vector<vector<int>> ans;
         for(int i=0;i<n;i++)
         {
            if(val[i]==0)
            {
                cout<<i<<endl;
                for(auto x:g[i])
                {
                    ans.push_back({i,x});
                }
            }
         }
         return ans;
    }

 void solve()
 {
    int nn;
    cin>>nn;
    vector<vector<int>> connection;
    for(int i=0;i<nn;i++)
    {
        int a,b;
        cin>>a>>b;
        connection.push_back({a,b});
    }
    vector<vector<int>> ans= criticalConnections(nn,connection);
    for(auto x:ans)
    {
        for(auto y:x)
        {
            cout<<y<<" ";
        }
        cout<<endl;
    }
 }
 signed main()
 {
   cin.tie(0); cout.tie(0);
   solve();
 }