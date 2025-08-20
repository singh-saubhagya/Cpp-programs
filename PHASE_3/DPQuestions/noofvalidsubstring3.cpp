#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
void solve()
{
    string str;
    cin>>str;
    vector<int> ends;
    int n=str.size();
    vector<int> dep;
    dep.push_back(0);
    int depth=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='(')depth++;
        else 
        depth--;
        dep.push_back(depth);
    }
    n=dep.size();
    stack<int> s;
    ends.assign(n+2,0);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        while(s.empty()==false && dep[s.top()]>=dep[i])
        {
            if(dep[i]==dep[s.top()])
            {
                ends[i]=1+ends[s.top()];
               
            } 
            s.pop();
        }
        ans+=ends[i];
        s.push(i);
    }
    cout<<ans<<endl;
}
signed main()
{
  cin.tie(0); cout.tie(0);
  solve();
}