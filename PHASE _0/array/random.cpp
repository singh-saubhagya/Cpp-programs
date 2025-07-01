#include<bits/stdc++.h>
using namespace std;
signed main()
{
    map<int,int> m;
    m.insert({0,1});
    auto it=m.begin();
    cout<<it->first<<" "<<it->second<<endl;
    it--;
    // if(it==m.end())
    // cout<<"Yes"<<endl;
}