
#include<bits/stdc++.h>
using namespace std;


int minTime(int n, vector<vector<int>>& edges) {
    vector<vector<int>> g(n);
    map<pair<int, int>, vector<pair<int, int>>> m;
    
    for(int i = 0; i < edges.size(); i++) {
        if(edges[i].size() <= 2)
            continue;
        vector<int> arr = edges[i];
        g[arr[0]].push_back(arr[1]);
        m[{arr[0], arr[1]}].push_back({arr[2], arr[3]});
    }

    priority_queue<pair<int, int>> pq;
    vector<int> dist(n+1, -1);
    vector<bool> mark(n+1, false);

    dist[0] = 0;
    pq.push({0, 0});  // starting node 0 with time 0

    while(!pq.empty()) {
        pair<int, int> val = pq.top();
        pq.pop();
        int tl = -val.first;
        int node = val.second;

        if(mark[node])
            continue;
        mark[node] = true;

        if(node == 1) {
            cout << tl << endl;
        }

        for(auto x : g[node]) {
            for(auto y:m[{node,x}])
                {
                    int a=y.first;
                    int b=y.second;
                      if(tl >= a && tl <= b) {
                int tnow = tl + 1;
                if(dist[x] == -1 || tnow < dist[x]) {
                    dist[x] = tnow;
                    pq.push({-tnow, x});
                }
            } else if(tl < a) {
                int tnow = a + 1;
                if(dist[x] == -1 || tnow < dist[x]) {
                    dist[x] = tnow;
                    pq.push({-tnow, x});
                }
            }
                }

          
        }
    }

    return dist[n-1];
}
signed main(){

    int n;
    cin>>n;
    vector<vector<int>> edges;
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        vector<int> arr;
        for(int j=0;j<4;j++)
        {
            int x;
            cin>>x;
            arr.push_back(x);
        }
        edges.push_back(arr);
    }
    cout<<minTime(n,edges);
}