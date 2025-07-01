#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
lli n,m,k;
vector< string > arr;
using ii=pair<lli,lli>;
using state=pair<ii,lli>;
vector<vector<vector<lli>>> dist;
#define inf 1e9
vector<state> neighbour(state st)
{
    vector <state> neigh;
    int dx[]={1,0,-1,0};
    int dy[]={0,1,0,-1};
    for(int i=0;i<4;i++)
    {
       int nx= st.first.first+dx[i];
       int ny= st.first.second+dy[i];
       if(nx>=0 && nx<n && ny>=0 && ny<m)
       {
         int temp=st.second;
            if(arr[nx][ny]=='#')
            {
                temp++;
            }
            if(temp>k)
            continue;
            neigh.push_back({{nx,ny},temp});
       }

    }
    return neigh;
}
void bfs(state st)
{
    queue<state> q;
    q.push(st);
    dist=vector<vector<vector<lli>>>(n,vector<vector<lli>>(m,vector<lli>(k+1,inf)));
    dist[st.first.first][st.first.second][st.second]=0;
    while(!q.empty())
    {
        state cur=q.front();
        q.pop();
        for(auto i:neighbour(cur))
        {
            if(dist[i.first.first][i.first.second][i.second]==inf)
            {
               dist[i.first.first][i.first.second][i.second]=dist[cur.first.first][cur.first.second][cur.second] +1; 
               q.push(i);
            }
        }
    }
    
}
signed main()
{
    cin>>n>>m>>k;
    arr.resize(n);
    ii st,en;
    for(lli i=0;i<n;i++)
    {
       cin>>arr[i];
    }
    for(lli i=0;i<n;i++)
    {
        for(lli j=0;j<m;j++)
        {
            if(arr[i][j]=='S')
            {
             st={i,j};
            }
            if(arr[i][j]=='E')
            {
             en={i,j};
            }
        }
    }
    bfs({st,0});
    lli best_dis=inf;
    for(int i=0;i<=k;i++){
        best_dis = min(best_dis,dist[en.first][en.second][i]);
    }
    cout<<best_dis<<endl;

}