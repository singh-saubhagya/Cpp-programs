#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
#define  state pair<lli,lli>
vector<vector<char>> arr(6, vector<char>(6));
state st;
state en;
vector<vector<lli>>vis;
vector<vector<lli>>dis;
vector<vector<state>> par;
vector<state> ng={{1,0},{-1,0},{0,1},{0,-1}};
#define inf 1e9
bool isvalid(lli row, lli col){
    if(row<0 || row >= 6 || col<0 || col>=6 )
    return false;
    if(arr[row][col]=='#')
    {
        return false;
    }
    return true;
}
vector<state> find_ng(state cur){
   vector<state> temp;
   for(auto x:ng){
    lli row=cur.first+x.first;
    lli col=cur.second+x.second;
    if(isvalid(row,col))
    {
        temp.push_back({row,col});
    }
   }
   return temp;
}
void bfs()
{ 
    vis=vector<vector<lli>>(6,vector<lli>(6,0));
    dis=vector<vector<lli>>(6,vector<lli>(6,100));
    par=vector<vector<state>>(6,vector<state>(6,{-1,-1}));
    queue<state> q;
    q.push(st);
    par[st.first][st.second]={-1,-1};
    vis[st.first][st.second]=1;
    dis[st.first][st.second]=0;
    while(q.empty()==false)
    {
        state cur=q.front();
        q.pop();
        for(auto x:find_ng(cur))
        {
            if(vis[x.first][x.second]==0)
            {
                vis[x.first][x.second]=1;
                dis[x.first][x.second]=dis[cur.first][cur.second]+1;
                par[x.first][x.second]=cur;
                q.push(x);
            }
        }
    }
    
}
signed main(){
 cout.flush();
 for(lli i=0;i<6;i++)
 {
  for(lli j=0;j<6;j++)
  {
    char ch;
    cin>>ch;
    arr[i][j]=ch;

    if(ch=='F')
    {
     en={i,j};
    }
    else if(ch == 'S'){
      st={i,j};
    }
  }

 }
 bfs();
 cout<<dis[en.first][en.second]<<endl;
 state cur=en;
 vector<state> temp;
 while(cur.first!=-1)
 {
    temp.push_back(cur);
    cur=par[cur.first][cur.second];

 }
 reverse(temp.begin(),temp.end());
 for(auto x:temp)
 {
    cout<<x.first<<" "<<x.second<<endl;
 }
}