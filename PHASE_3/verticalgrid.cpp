#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> ng={{1,0},{-1,0},{0,-1},{0,1}};
vector<pair<int,int>> bfs(vector<vector<int>> &vis, vector<vector<int>> &g, int i, int j, int n ,int k)
{
    int color=g[i][j];//color
    queue<pair<int,int>> q;
    q.push({i,j});
    vis[i][j]=1;
    int sz=1;
    vector<pair<int,int>> comp;
    comp.push_back({i,j});
    while(q.empty()==false)
    {
        
        auto x=q.front();
        q.pop();
        for(auto z:ng)
        {
            int row=z.first+x.first;
            int col=z.second+x.second;
            if((row>=0 && row < n && col >=0 && col <10)&& g[row][col]==color && vis[row][col]==0)
            {
                q.push({row,col});
                vis[row][col]=1;
                sz++;
                comp.push_back({row,col});
            }
            
        }
    }
    if(sz>=k)
    {
        return comp;
    }
    else return {};
    
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<string> arr;
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        arr.push_back(str);
    }      
    vector<vector<int>> g;
    g.resize(n,vector<int>(10));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<10;j++)
        {
            g[i][j]=arr[i][j]-'0';
        }
    }
    
    while(1)
    {
        bool flag=false;
        vector<vector<int>> vis;
        vis.resize(n,vector<int>(10,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<10;j++)
            {

                vector<pair<int,int>> res;
                if(vis[i][j]==0 && g[i][j]!=0)
                res=bfs(vis,g,i,j,n,k);
                for(auto x:res)
                {
                    flag=true;
                    g[x.first][x.second]=0;
                }
            }
         }
         for(int j=0;j<10;j++)
         {
            vector<int> temp;  
            for(int i=n-1;i>=0;i--)
            {
                if(g[i][j]!=0)
                {
                    temp.push_back(g[i][j]);
                }
            }
            int pt=n-1;
            for(int i=0;i<temp.size();i++)
            {
                g[pt][j]=temp[i];
                pt--;
            }
            for(int i=pt;i>=0;i--)
            {
                g[i][j]=0;
            }

         }
         if(flag==false)
         break;
    }

         for(int i=0;i<n;i++)
         {for(int j=0;j<10;j++)
            {
                cout<<g[i][j];
            }cout<<endl;}  
    
    return 0;
}