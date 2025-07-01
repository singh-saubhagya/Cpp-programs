#include<bits/stdc++.h>
using namespace std;

int main()
{

    int n,m;
    cin>>n>>m;
    vector<vector<int>> g;
    g.resize(n+1);
    vector<int> idx;
    idx.assign(n+1,0);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        idx[b]++;
    }
    priority_queue<int> pq;

    for(int i=1;i<=n;i++)
    {
        if(idx[i]==0)
        {
            pq.push(-i);
        }
    }
    vector<int> ans;
    ans.resize(n+1);
    int pt=1;
    while(pq.empty()==false)
    {
        auto x=-pq.top();
        pq.pop();
        ans[x]=pt;
        pt++;
        for(auto z:g[x])
        {
            idx[z]--;
            if(idx[z]==0)
            {
                pq.push(-z);
            }
        }

    }
   
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
  
    return 0;
}