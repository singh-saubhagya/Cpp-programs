#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
#define inf 1e18


/*
IN dijkstar we  relax all the ng for a node s if dist via a path s is lesser than the path already save in dist[ng], ng is neighbour of s.
Then add all the relaxed dist in the p.q. , then we pop out the min dist among all the dist in p.q. and finalize its dist by using the marked vector.
i.e if we pop out 5 having dist as 3 , then dist[5]=3 is the shortest distance from the source node. 
We can prove this:
We know all the other paths in p.q. will have distance as greater than 3 , thus if there exist a path via all these nodes having dist > 3 and ending at node 5 will have dist > 3 , (only when we have all the edges in the g have +ve weight)
But if we say there is negaitve weights present in the array, then dijkstra will not work.
refer to e.g. in rev of graph notebook.
*/

signed main()
{

  lli n,m;
  cin>>n>>m;
  vector<vector<pair<lli,lli>>> g;
  g.resize(n+1);

  // use of marked and dis array is necessary everywhere you are using dijkstra
  vector<bool> marked(n+1,false);
  vector<lli> dis(n+1,inf);
  for(lli i=0;i<m;i++)
  {
    lli a,b,c;
    cin>>a>>b>>c;
    g[a].push_back({b,c});
  }
  priority_queue<pair<lli,lli>> pq;
  pq.push({0,1});// {dist,node}
  dis[1]=0;// always set of the source node but not the marked .
  while(pq.empty()==false)
  {
    pair<lli,lli> x=pq.top();
    pq.pop();//every time we are popping we are getting a pair of {dist,node},eg.{3,5} dist is the min among all the distance in the p.q. and according to dijkstra.
    // this is the most optimal path we can take via a node 5 having the min path length of 3, but from this we can't say all its neighbours will have the smallest distance , it totally depends upon the edge weight.
    if(marked[x.second])// if it is false means the node has got its optimal value and we wil now set it true, as in futue greter distances may be poppep out , which we don't want to relax with .
    continue;
    marked[x.second]=true;
    for(auto z:g[x.second])
    {
        lli dt=z.second;
        lli node=z.first;
        lli temp=dt+abs(x.first);
        if( temp<(dis[node]))// now we are relaxing all the edges. which means we have found an another path such that dist via this path is lesser that we found out before via another path.
        {
            dis[node]=temp;// this can only we assigned when temp is lesser than dis[node]. if it is greater no need to assign and push
            pq.push({-temp,node});// we have found new path, 
        }
    }

  }
  for(int i=1;i<=n;i++)
  {
    cout<<dis[i]<<" ";
  }
  cout<<endl;
}