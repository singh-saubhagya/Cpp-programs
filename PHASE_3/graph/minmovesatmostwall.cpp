#include <bits/stdc++.h>
using namespace std;

/*
3 4 2
S###
###E
.#..
*/
#define INF 1e9
#define F first
#define S second
using ii = pair<int,int>;
using state = pair<ii,int>;

int n,m,k;
vector<string> arr;
vector<vector<vector<int>>> dis;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
bool inside(int x,int y){
    if(x<0||x>=n||y<0||y>=m)return 0;
    return 1;
}

vector<state> get_neighbour(state cur){
    vector<state> res;
    for(int dir=0;dir<4;dir++){
        int nx = cur.F.F + dx[dir];
        int ny = cur.F.S + dy[dir];
        if(inside(nx,ny)){
            int nz = cur.S;
            if(arr[nx][ny]=='#'){
                nz++;
            }
            if(nz>k)continue;
            res.push_back({{nx,ny},nz});
        }
    }
    return res;
}

void bfs(state st){
    queue<state> q;
    dis = vector<vector<vector<int>>>(n,vector<vector<int>>(m,vector<int>(k+1,INF)));
    // ((x,y),z) -> at cell x,y with z walls broken till now.
    dis[st.F.F][st.F.S][st.S] = 0;
    q.push(st);
    // bfs code
    while(!q.empty()){
        state cur = q.front();
        q.pop();
        // for all its neighbour... check and update. // Relax 
        for(auto v:get_neighbour(cur)){
            if(dis[v.F.F][v.F.S][v.S]==INF){
                dis[v.F.F][v.F.S][v.S] = dis[cur.F.F][cur.F.S][cur.S]+1;
                q.push(v);
            }
        }
    }
}

int main()
{
    cin>>n>>m>>k;
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ii st,en;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='S'){
                st = {i,j};
            }else if(arr[i][j]=='E'){
                en = {i,j};
            }
        }
    }
    
    bfs({st,0});
    int best_dis = INF;
    for(int i=0;i<=k;i++){
        best_dis = min(best_dis,dis[en.F][en.S][i]);
    }
    cout<<best_dis<<endl;
}