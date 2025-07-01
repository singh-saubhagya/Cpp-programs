#include<bits/stdc++.h>
using namespace std;

typedef long long lli;
#define inf 1e9
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    lli n;
    cin>>n;
    vector<vector<lli>> dist;
    dist.resize(n+1,vector<lli>(n+1));
    vector<vector<lli>> dis;
    dis.assign(n+1,vector<lli>(n+1,inf));
    for(lli i=1;i<=n;i++){
        for(lli j=1;j<=n;j++){
            cin>>dist[i][j];
        }
    }
    vector<lli> temp;
    for(lli i=1;i<=n;i++)
    {
        lli x;
        cin>>x;
        temp.push_back(x);
    }
     // adjust indices to 1-based
    vector<lli> arr;
    vector<lli> ans;
    ans.resize(n);
    for(lli k=n-1;k>=0;k--){
        lli node=temp[k];// relax with this node
        lli sum=0;
        arr.push_back(node);
        for(auto x:arr)
        {
            for(auto y:arr)
            {
                dis[x][y]=min(dis[x][y],dist[x][node]+dist[node][y]);
                sum+=dis[x][y];
            }
        }
        ans[k]=sum;

    }
    for(lli i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout << '\n';
    return 0;
}
