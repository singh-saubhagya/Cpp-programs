#include<bits/stdc++.h>
using namespace std;

void rec(vector<int> &arr, int n ,multimap<int,int> & m , int level, vector<int> &ans){
    if(level==n)
    {
        // base case 
        for(auto x:ans)
        cout<<x<<" ";
        cout<<endl;
        return;
    }
    else if (level>n)
    {
        // prune
        return; 
    }
    for(auto it = m.begin();it!=m.end();it++)
    {
        if(it->second>0)
        {
            // valid choice 
            // put this element at the level +1 pn
            ans.push_back(it->first);
            it->second=0;
            level++;
            rec(arr,n,m,level,ans);

            ans.pop_back();
            it->second=1;
            level--;

            
        }
    }

}
signed main()
{
    int n;
    cin>>n;
    vector<int> arr;
    arr.resize(n);
    multimap<int,int> m;
    for(int i=0;i<n;i++)
    {
    cin>>arr[i];
    m.insert({arr[i],1});
   
    }
    int level=0;
    vector<int> ans;
    
    rec(arr,n,m,level,ans);
}