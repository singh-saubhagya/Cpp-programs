#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
using ii=pair<lli,lli>;
lli n,m;
vector<vector<ii>> gph;
vector<lli> visited;
double t=0;
void input()
{
    cin>>n>>m;
    gph.resize(n+1);
     visited.resize(n+1,0);
     
    for(lli i=1;i<=m;i++)
    {
        lli a,b,c;
        cin>>a>>b>>c;
        gph[a].push_back({b,c});     
        gph[b].push_back({a,c});     
    }
}
void burnthemall(lli s)
{
    priority_queue<ii> q;
    q.push({0,s});
    while(!q.empty())
    {
        ii cur=q.top();
        q.pop();
        lli nd=cur.second;// node
        lli l=abs(cur.first);// edge length remaining
        t+=l;
       
        priority_queue <ii> pq;
        if(visited[nd])
        continue;
        visited[nd]=1;
        while(!q.empty())
        {
            ii w=q.top();
            lli rem=abs(w.first)-l;
           
            if(w.second==nd)
            {
               
                t+=((double)rem)/2.0;
                visited[w.second]=1;
            }
            else
            {
                
                pq.push({-rem,w.second});
            }
            q.pop();

        }
        
        q=pq;
        for(ii i:gph[nd])
        {
            if(!visited[i.first])
            {q.push({-i.second,i.first});}
            
        }

    }

}
signed main()
{
  
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  input();
  lli source;
  cin>>source;
  burnthemall(source);
  t=t*10;
  cout<<t;
}