
         #include<bits/stdc++.h>
         using namespace std;
        #define inf 1e9
        typedef long long lli;
        int secondMinimum(int  n, vector<vector<int >>& edges, int  time, int change) {
            vector<vector<int>> g;
            g.resize(n+1);
            for(auto x:edges)
            {
                g[x[0]].push_back(x[1]);
                g[x[1]].push_back(x[0]);
            }
            vector<lli > vis;
            vis.resize(n+1,0);
            vector<lli > dist;
            dist.resize(n+1,inf);
            dist[1]=0;
            priority_queue<pair<lli ,lli >> pq;
            pq.push({0,1});
            while(pq.empty()==false)
            {
                auto x=pq.top();
                pq.pop();
                lli node=x.second;
                lli dt=abs(x.first);
                if(vis[node]==2)
                continue;
                if(vis[node]==0)
                {
                    vis[node]=1;
                    dist[node]=dt;
                }
                else if(vis[node]==1)
                {
                   
                    if(dist[node]<dt)
                    { 
                        vis[node]=2;
                        dist[node]=dt;
                    }
                }
                for(auto z:g[node])
                {
                     lli a=z;//node
                     lli wt=time;// weight
                     if(vis[a]!=2)
                     {
                        lli c=wt + dt;
                        lli k=2*change;
                        if(a==n && vis[a]==1)
                        {
                            // don't relaxed this one as we don't have to leave the final node
                        }
                        else if(c%k<change)
                        {
                            // no need to change the weight
                        }
                        else if(c%k>=change)
                        {
                            lli temp=floor(c/k)*k+k;
                            c=temp;
                        }
                        // these two elseif condition is used to calculate the time needed to leave the destination node.
                        pq.push({-c,a});
                     }
                }
            }
            if(vis[n]==2)
            return dist[n];
            return -1;
        }
        int main()
        { 
            int time;
            int change;
            int n, m;
            cin >> n >> m;
            cin >> time;
            cin >> change;
        
            vector<vector<int>> edge(m, vector<int>(2)); // Correct initialization
            for(int i = 0; i < m; i++)
            {
                cin >> edge[i][0] >> edge[i][1];
            }
        
            cout << secondMinimum(n, edge, time, change) << endl;
            return 0;
        }
   

        /*
        
        
        #include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define inf 1e9
lli  secondMinimum(lli  n, vector<vector<lli >>& edges, lli  time, lli  change) {
    vector<vector<lli>> g;
    g.resize(n+1);
    for(auto x:edges)
    {
        g[x[0]].push_back(x[1]);
        g[x[1]].push_back(x[0]);
    }
    queue<pair<lli,lli>> q;
    q.push({1,0});
    vector<lli> dist1,dist2;
    dist1.assign(n+1,inf);
    dist2.assign(n+1,inf);
    dist1[1]=0;
    vector<lli> vis;
    vis.assign(n+1,0);
    while(q.empty()==false){
        lli node=q.front().first;
        lli dt=q.front().second;
        q.pop();
        if(vis[node]==0)
        {
            dist1[node]=dt;
            vis[node]=1;
        }
        else if(vis[node]==1 && dist1[node]<dt)
        {
            dist2[node]=dt;
            vis[node]=2;
        }
        else 
        continue;
        for(auto x:g[node]){
            lli t;
            lli a=dt/(2*change);
            t=a*2*change;
            lli b=dt%(2*change);
            if(b<change)
            {
                t+=b;
            }
            else
            {
                t+=2*change;
            }
            t+=time;
            if(vis[x]==2)
            continue;
            else
            {
                q.push({x,t});
            }
        }

    }
    if(vis[n]==2)
    cout<<dist2[n]<<endl;

}
signed main(){
    lli m;
    cin>>m;
    vector<vector<lli>> edges;
    edges.resize(m);
    for(lli i=0;i<m;i++){
        lli a,b;
        cin>>a>>b;
        edges[i].push_back(a);
        edges[i].push_back(b);
    }
    lli n;
    cin>>n;
    lli time,change;
    cin>>time>>change;
    secondMinimum(n,edges,time,change);
}
        */