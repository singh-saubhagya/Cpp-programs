#include<bits/stdc++.h>
using namespace std;
#define f first
    #define s second
   using pp = pair<int, int>;
   struct pair_hash {
    size_t operator()(const pp& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};
    int findparent(int node, vector<int> &parent)
    {
        if(parent[node]==node)
        return node;
        
        return parent[node]=findparent(parent[node],parent);
    }
    int minTime(int n, vector<vector<int>>& edges, int k) {

        unordered_map< pp ,int,pair_hash> m;
        for(auto x:edges)
        {
            int a=x[0];
            int b=x[1];
            int c=x[2];
            int temp=a;
            a=min(a,b);
            b=max(temp,b);
            m[{a,b}]=max(c,m[{a,b}]);
        }    
        vector<pair<int,pp>> arr;
        for(auto x:m)
        {
            pp p=x.f;
            int val=x.s;
            arr.push_back({val,p});
        }
        sort(arr.begin(),arr.end());
        int ans=0;
        int ct=n;
        int nn=arr.size();
        vector<int>parent;
        parent.resize(n);
        for(int i=0;i<n;i++)
        parent[i]=i;


        for(int i=nn-1;i>=0;i--)
        {
            pair<int,pp> temp=arr[i];
            int tt=temp.first;
            pp p=temp.second;
            int a=p.first;
            int b=p.second;
            a=findparent(a,parent);
            b=findparent(b,parent);
            if(a!=b)
            {
                ct--;
                parent[a]=b;
                if(ct<k)
                {
                    ans=tt;
                    break;
                }
            }

        }
        return ans;

    }
signed main()
{
    
}