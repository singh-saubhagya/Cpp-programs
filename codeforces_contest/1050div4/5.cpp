#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
const int inf=1e9;
void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> g;
    g.resize(n);
    vector<int> sz;
    int msz=0;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        sz.push_back(k);
        vector<int>temp;
        temp.resize(k);
        for(int i=0;i<k;i++)
        {
            cin>>temp[i];
        }
        g[i]=temp;
        msz=max(msz,k);
    }
    cout<<msz<<endl;
    vector<vector<int>> gg;
    gg.resize(n);
    for(int i=0;i<n;i++)
    {
        int k;
        k=sz[i];
        gg[i].resize(msz);
        for(int j=0;j<k;j++)
        {
            gg[i][j]=g[i][j];
        }
        for(int j=k;j<msz;j++)
        gg[i][j]=inf;

    }
   
    vector<int> ans;
    ans.resize(msz);
    vector<int> prob;
    for(int i=0;i<n;i++)
    {
        prob.push_back(i);
    }
    for(int i=0;i<msz;i++)
    {
        int mval=inf;
        vector<int> next;
        for(int j=0;j<prob.size();j++)
        {

            int row=prob[j];
            int val2=gg[row][i];
            
            if(val2<mval)
            {
                mval=val2;
                next.clear();
                next.push_back(row);
            }
            else if(val2==mval)
            {
                next.push_back(row);
            }
        }
        ans[i]=mval;
        // update the next i
        prob=next;
    }
    for(int i=0;i<msz;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
signed main()
{
  cin.tie(0); cout.tie(0);
  int t;cin>>t;while(t--)solve();

}