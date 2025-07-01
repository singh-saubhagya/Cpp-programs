#include<bits/stdc++.h>
using namespace std;
typedef long long lli; 
vector<lli> topo; vector<vector<lli>> g;
vector<vector<lli>> idg;
vector<lli> dp;
// lli rec(lli node)
// {
//     lli ans=0;
//     if(node==1)
//     {
//         return 1;
//     }
//     if(idg[node].empty()==true)
//     return -1;  
//     for(auto x:idg[node])
//     {
//         lli temp=rec(x);
//         if(temp==-1)
//         continue;
//         ans+=temp;
//     }
//     return ans;
// }
int main()
{ 
    lli n,m;
   
    cin>>n>>m;
    dp.resize(n+1);
    g.resize(n+1);
    vector<lli> id;
    id.resize(n+1,0);
    idg.resize(n+1);
    for(lli i=0;i<m;i++)
    {
        lli a,b;
        cin>>a>>b;
        g[a].push_back(b);
        idg[b].push_back(a);
        id[b]++;
    }
    // for(lli a=1;a<=n;a++)
    // {
    //     cout<<a<<":";
    //     for(auto b:idg[a])
    //     {
    //         cout<<b<<" ";
    //     }
    //     cout<<endl;
    // }
    priority_queue<lli> pq;
    for(lli i=1;i<=n;i++)
    {
        if(id[i]==0)
        {
            pq.push(-i);
        }
    }
    dp[1]=1;
    while(pq.empty()==false)
    {
        auto x=-pq.top();
        pq.pop();
        topo.push_back(x);
        for(auto z:g[x])
        {
            id[z]--;
            if(id[z]==0)
            {
                pq.push(-z);
            }
        }
        for(auto prev:idg[x])
        {
            dp[x]=(dp[x]+dp[prev])%(1000000000+7);
        }
    }
    cout<<dp[n]<<endl;
   
    return 0;
}