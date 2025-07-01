#include<bits/stdc++.h>

using namespace std;

// maximum subarray problems are solves using contribution technique
void enigma(){
    int n;
    cin>>n;
    vector<int> arr;
    arr.resize(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    vector<int> idx1,idx2;
    idx1.assign(n,-1);// -1 denotes there doesn't exist any element greater than this in the rhs
    idx2.assign(n,-1);//// -1 denotes there doesn't exist any element greater than this in the lhs
    stack<int> s1,s2;
    for(int i=0;i<=n-1;i++)
    {
        while(s1.empty()==false && arr[s1.top()]<arr[i])
        {
            int x=s1.top();
            idx1[x]=i;
            s1.pop();

        }
        s1.push(i);
    }
 
    for(int i=n-1;i>=0;i--)
    {
        while(s2.empty()==false && arr[s2.top()]<=arr[i])
        {
            int x=s2.top();
            idx2[x]=i;
            s2.pop();

        }
        s2.push(i);
    }
    vector<int> temp;
    for(int i=0;i<n;i++)
    {
        int a,b;
        a=idx1[i];
        b=idx2[i];
        if(idx1[i]==-1)
        a=n; // calculating end poins of subarray if arr[i] is greatest in the rhs
        if(idx2[i]==-1)
        b=-1;// calculating end poins of subarray if arr[i] is greatest in the lhs

        a=a-i;// no of ending points in rhs
        b=i-b;// no of ending points in the lhs 
        for(int j=1;j<=a*b;j++)
        temp.push_back(arr[i]);
    }
    sort(temp.begin(),temp.end());
    for(auto x: temp)
    cout<<x<<" ";
    cout<<endl;
    
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    enigma();
}