#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
    string str;
    cin>>str;
    int l=str.length();
    vector<int> arr;
    arr.resize(l+1);
    int depth=0;
    int a=-l;
    int b=l; 
    arr[0]=0;
    for(int i=1;i<=l;i++){
        char ch=str[i-1];
        if(ch=='(')
        {
            depth++;
        }
        else 
        {
            depth--;
        }
        a=max(a,depth);
        b=min(b,depth);
        arr[i]=depth;
    }
    vector<int> ns;
    ns.resize(l+1);

    stack<int> s;
    for(int i=0;i<=l;i++)
    {
        int val=arr[i];
        while(s.empty()==false && arr[s.top()]>=val)
        {
            s.pop();
        }
        if(s.empty()==false)
        {
            ns[i]=s.top();
        }
        else 
        {
            ns[i]=-1;
        }
        s.push(i);
    }
    map<int,vector<int>> m;
    for(int i=0;i<=l;i++)
    {
        int val=arr[i];
        m[val].push_back(i);
    }
    int ans=0;
    for(int i=1;i<=l;i++)
    {
        int val=arr[i];
        int prev=ns[i];
        vector<int> temp=m[val];
        auto r=lower_bound(temp.begin(),temp.end(),i);
        auto l=upper_bound(temp.begin(),temp.end(),prev);
        ans+=r-l;
    }
    cout<<ans<<endl;
   
}
signed main()
{
    solve();
}