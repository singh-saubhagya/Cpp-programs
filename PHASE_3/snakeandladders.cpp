#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
void game(){
    
    vector<vector<pair<int,int>>> g;
    g.resize(101);
    for(int i=1;i<=100;i++){
        for(int j=1;j<=6;j++){
            int idx=i+j;
            if(idx<=100)
            {
                g[i].push_back({idx,1});
            }
        }
       }
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].clear();
        g[a].push_back({b,0});
    }
   int m;
   cin>>m;
   for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].clear();
        g[a].push_back({b,0});
   }
  
//    for(int i=1;i<10;i++){
//     for(auto x:g[i]){
//         cout<<x.first<<" ";
//     }
//     cout<<endl;
//    }


   vector<int>dist;
   dist.assign(101,inf);
   deque<int> dq;
   dist[1]=0;                               
   dq.push_back(1);
   while(dq.empty()==false){
    auto val=dq.front();
    dq.pop_front();
    for(auto y:g[val])
    {
        int pn=y.first;
        int wt=y.second;
        int dt=dist[val]+wt;
        if(dt<dist[pn])
        {
            dist[pn]=dt;
            if(wt==0){
                dq.push_front(pn);
            }
            else{
                dq.push_back(pn);// all the distance in the deque will be less or equal to dt

            }
        }
    }
   }
 
   if(dist[100]<inf)
   cout<<dist[100]<<endl;
   else
   cout<<-1<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        game();
    }
}