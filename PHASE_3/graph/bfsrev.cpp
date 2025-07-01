#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define tab '\t' 
lli n,m;
vector<vector<lli>> gph;
vector<lli> visited;
vector<lli> dist;
#define  inf 1e9
void bfs(lli s)
{
    queue <lli> q;
    q.push(s);
    visited[s]=1;
    dist[s]=0;// always remember to assign these visited and dist of the soure node before starting the while loop
    while(!q.empty())
    {
        lli ele=q.front();
        
        q.pop();
        for(auto i:gph[ele])
        { 
            /*
            if(!visited[i])
            {
                
                visited[i]=1;
                dist[i]=dist[ele]+1;
                q.push(i);
            }
           */
           // in place of above condn we can use this cond also


            if(dist[i]==inf)// this condition means we are pushing the each vertice in the queue only once. and after that its dis will be updated.
            {
             // ele is parent of node i and so no of ways to reach i will equal to no of ways to reach node ele.
            dist[i]=dist[ele]+1;// assigning the closes distance form the source node. because all the weights in the g are uniform and popping from queue is giving the min distance for node ele. and adding 1 which is setting the min dist of i.
            q.push(i);
            }
            else
            {
            // this means i is already visited with a path length less than or equal to dist[ele]+1;
            // here we can also count the no of shortest path form source node.
            // if path length of already visited node is equal to the current lenght of the path i.e. dist[ele]+1, then no of ways to reach node 
            // i equal to x+y, where x represent no of ways to reach parent(x) and y represent no of ways to reach node ele.
            }
        }
    }
}
signed main()
{
    cin>>n>>m;
    gph.resize(n+1);
    visited.resize(n+1,0);
    dist.resize(n+1,inf);
    for(lli i=1;i<=m;i++)
    {
        lli a,b;
        cin>>a>>b;
        gph[a].push_back(b);
    }
    bfs(1);
}