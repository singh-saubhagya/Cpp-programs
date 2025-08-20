#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
void solve()
{
    string str;
    cin>>str;
    int n=str.length();
    int depth=0;
    vector<int> dep;
    dep.push_back(0);
    for(int i=0;i<n;i++)
    {
        if(str[i]=='(')
        depth++;
        else 
        depth--;
        dep.push_back(depth);
    }
    vector<int> psml;
    psml.resize(n+4);
    stack<int> s;
    n=dep.size();
    for(int i=0;i<n;i++)
    {
        while(s.empty()==false && dep[s.top()]>=dep[i])
        s.pop();
        if(s.empty())
        psml[i]=-1;
        else
        psml[i]=s.top();
        s.push(i);
       
    }
    map<int , vector<int>> nidx;
    for(int i=0;i<n;i++)
    {
        nidx[dep[i]].push_back(i);
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int r=i;
        int l=psml[i];
        vector<int> temp=nidx[dep[i]];
        auto it1=lower_bound(temp.begin(),temp.end(),l);
        auto it2=lower_bound(temp.begin(),temp.end(),r);
        int diff=it2-it1;
        ans+=diff;
    }
    cout<<ans<<endl;
}
signed main()
{
  cin.tie(0); cout.tie(0);
  solve();
}