#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
vector<vector<lli>> g;
vector<lli> vis;
// undirected : two things to remember, one is parent child edge and the other unvisied edge pointing to the visited node, 
// directed no need to add the parennt child condition
void dfs(lli cur)
{
    vis[cur] = 1;// this conditon is madatory whereever you used dfs.
    for (auto x : g[cur]) {
        // inside this loop we can make conclusion there is a edge betweem x and cur

        if (!vis[x]) {
            // here we can make a conclusion, that node cur is parent of x and there exist an edge between cur and x , 
           
            dfs(x);
        }
        else  {
            // this means that there is edge E between x and cur but x is already visited by some another path.
            // this E could also be an edge towards its parent which means x is parent of cur.
            // if this E is not towards the parent edge and graph is undirected  , then their exist a cycle in the graph. starting x and ending when parent of node(cur) say y then parent of node(y) and so on is equal to x. 
        

            // for directed graph , this parent child relation ship is slight different. as we can have to add condn in else where x is the ancestor of cur or not.
            // in simple words  x could be a node , whose all the ng are visited or could be a node whose some of the ng are visited.
            // and we say that any node is fully visited only when all its ng are visited via dfs,
            // so if there is edge between cur and x and x is fully visited , then cur is not an child of x , because if it had been it should have been visited earlier before x.
            // and the current dfs doesn't contain x as one of the nodes getting explored.
            // so for cycle detection if x is the node whose all the ng have not yet visited then , there is cycle. 


        }
    }
}
signed main(){
    lli n, m;
    cin >> n >> m;
    g.resize(n + 1);
    vis.resize(n + 1, 0);
    for (lli i = 0; i < m; i++) {
        lli a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (lli i = 1; i <= n; i++) {
        if (!vis[i]) {         
            dfs(i);
            // here we can say no of time dfs is called with different source node , there are that no of components present.
        }
    }
}