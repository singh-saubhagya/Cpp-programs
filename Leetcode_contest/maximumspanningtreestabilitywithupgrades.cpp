#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
 #define inf 1e9
    int findparent(int node, vector<int>&parent)
    {
        if(parent[node]==node)
        return node;
        return parent[node]=findparent(parent[node],parent);
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        vector<int> parent;
        parent.resize(n+2);
        for(int i=0;i<=n;i++)
            parent[i]=i;
        int ct=n;
        int tt=inf;
        vector<pair<int,pair<int,int>>> arr;
        for(auto x:edges)
            {
                int a=x[0];
                int b=x[1];
                int c=x[2];
                int d=x[3];
                
                if(d)
                {
                    a=findparent(a,parent);
                    b=findparent(b,parent);
                    tt=min(tt,c);
                    if(a!=b)
                    {
                        parent[a]=b;
                        ct--;
                    }
                    else 
                    return -1;
                }
                else 
                {
            
                    arr.push_back({c,{a,b}});
                }
            }
        sort(arr.begin(),arr.end());
        if(ct==1)
            return tt;

        int n1=arr.size();
        int ne=ct-1;
        vector<int> ans;

        for(int i=n1-1;i>=0;i--)
        {
            pair<int,pair<int,int>> x=arr[i];
            int val=x.first;
            int a=x.second.first;
            int b=x.second.second;
            a=findparent(a,parent);
            b=findparent(b,parent);
            if(a!=b)
            {
                ans.push_back(val);
                parent[a]=b;
                ne--;
                if(ne==0)
                break;
            }
        }  
        if(ne>0)
        return -1;

        int nn=ans.size();
        reverse(ans.begin(),ans.end());
        int sol=inf;
        for(int i=0;i<k;i++)
        {
            if(i<nn)
            {
                int val=ans[i]*2;
                sol=min(sol,val);
            }
            else break;
        }
        if(k<nn)
        sol=min(sol,ans[k]);

        sol=min(sol,tt);
        if(sol>=inf)
        return -1;
        else return sol;
    }

   
int main()  // ⚠️ typo was here: 'igned main()' → 'int main()'
{
    freopen("input.txt", "r", stdin);
    
    int n, k;
    if (!(cin >> n >> k)) {
    cerr << "Failed to read n and k from input!" << endl;
    return 1;
}

    cin.ignore();  // clear leftover newline after reading n and k

    vector<vector<int>> edges;
    string line;

    // read till EOF
    while (getline(cin, line)) {
        stringstream ss(line);
        int num;
        vector<int> arr;

        while (ss >> num)
            arr.push_back(num);

        edges.push_back(arr);
    }

    cout << "maxStability: " << maxStability(n, edges, k) << endl;

    for (auto x : edges) {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }

    return 0;
}