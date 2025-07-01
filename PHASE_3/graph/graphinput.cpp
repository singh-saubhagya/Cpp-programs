#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
struct graph{
    lli n,m;
    vector<vector<lli> >gph;
    vector<vector<lli>> gph1;
    // void inputlist()
    // {
    //     cin>>n>>m;
    //     gph.resize(n+1);
        // for(lli i=1;i<=m;i++)
        // {
        //     lli a,b;
        //     cin>>a>>b;
        //     gph[a].push_back(b);//for directed
        //     // if undirected add g[b].push_back(a) also
        // }

    // }   
    void inputmatrix()
    {
        cin>>n>>m;
        gph1.resize(n+1);
        for(lli i=1;i<=n;i++)
        {
            gph1[i].resize(n+1,0);   
        }
        for(lli i=1;i<=m;i++)
        {
            int a,b;
            cin>>a>>b;
            gph1[a][b]=1;  
        }

    }
};
void solve(graph g)
{
    for(lli i=1;i<=g.n;i++)
    {
        cout<<endl<<"Neighbours of "<<tab<<i<<endl;
        for(int j=1;j<=g.n;j++)
        {
            if((g.gph1[i][j]))
            cout<<tab<<j;
        }
        cout<<endl;
    }
}
signed main()
{

  lli q;
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cout<<endl;
  graph g;
  g.inputmatrix();
  solve(g);


}