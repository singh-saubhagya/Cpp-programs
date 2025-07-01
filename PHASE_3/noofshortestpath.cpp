#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
#define endl '\n'
using state=pair<pair<int,int>,int>;
vector<pair<int,int>> ng={{1,0},{-1,0},{0,-1},{0,1}};
signed main(){
    int n;
    cin>>n;
    vector<string>g;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        g.push_back(str);
    }
    int k;
    cin>>k;
    pair<int,int> st,en;
    
    //g[i][j] will represent character of string of ith row and jth coloumn;
    for(int i=0;i<n;i++)
    {
        string str=g[i];
        for(int j=0;j<n;j++){
            if(str[j]=='S'){
                st={i,j};

            }
            if(str[j]=='F'){
                en={i,j};
            }
        }
    }
    // since we have to find the shortest path to reach the destinaiton , by breaking atmost k walls , 
    //it can be possible we can  reach the destination by breaking less than k walls and at the same time 
    //the destination is not reachable by breaking k walls , therefore we need to store the distance i,j with 0 , 1 , 2 , ....k walls broken.
    vector<vector<vector<int>>> dist;
    dist.assign(n+1,vector<vector<int>>(n+1,vector<int>(k+1,inf)));
    // since this is bfs we can use dist array as the visited array;


    vector<vector<vector<int>>> path;//no of paths
    path.assign(n+1,vector<vector<int>>(n+1,vector<int>(k+1,0)));

    state beg={{st.first,st.second},0};
    queue<state> q;
    q.push(beg);
    dist[st.first][st.second][0]=0;
    path[st.first][st.second][0]=1;
    while(q.empty()==false){
        state val=q.front();
        q.pop();
        int i=val.first.first;
        int j=val.first.second;
        int w=val.second;//walls broken till now 
        for(auto x:ng){
            int row=x.first+i;
            int col=x.second+j;
            if(row>=0 && row<n && col>=0 && col<n){
                int wn=w;
                if(g[row][col]=='#'){
                    wn++;
                }
                if(wn>k)
                continue;
                if(dist[row][col][wn]==inf){
                    dist[row][col][wn]=dist[i][j][w]+1;
                    state nw={{row,col},wn};

                    path[row][col][wn]=path[i][j][w];
                    q.push(nw);

                }
                else if(dist[row][col][wn]==dist[i][j][w]+1)// we have to find the no of shortest path, therefore we are using this else if conditon otherwise we will use only else condn to find all the paths to reach node 
                {
                    path[row][col][wn]+=path[i][j][w];
                }
            }
        }
    }
    int ans=INT_MAX;
    state temp;
    for(int i=0;i<=k;i++)
    {
       if(dist[en.first][en.second][i]<ans)
       {
        ans=dist[en.first][en.second][i];
        temp={{en.first,en.second},i};
       }

    }
    if(ans==inf){
        cout<<"NOT POSSIBLE";
    }
    else
    {
    cout<<ans<<endl;
    cout<<path[temp.first.first][temp.first.second][temp.second]<<endl;
    }
}