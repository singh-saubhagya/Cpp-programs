#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
vector<int> twoSum(vector<int>& nums, int target) 
{
    vector<int> result;
    set<pair<int,int>> arr;
    for(int i=0;i<nums.size();i++)
    {
        pair<int ,int> p;
        p.first=nums[i];
        p.second=i;
        arr.insert(p);
    }
    auto st=arr.begin();
    auto en=--arr.end();
    while(1)
    {
        pair<int,int> a=*st;
        pair<int,int> b=*en;
        if(a.first+b.first==target)
        {
            result.push_back(a.second);
            result.push_back(b.second);
            return result;
        }
        else if(a.first+b.first>target)
        {
            en--;
        }
        else
        st++;
    }
    



}        
int main()
{
    vector<int> arr;
    int n,t;
    cin>>n>>t;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    vector<int> result=twoSum(arr,t);
    for(int i:result)
    {
        cout<<i<<tab;
    }
}