#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
    int n,r,b;
    cin>>n>>r>>b;
    vector<int> arr(b+1,0);
    for(int i=0;i<r;i++)
    {
        arr[i%(b+1)]++;
    }
    for(int i=0;i<=b;i++)
    {
       for(int j=0;j<arr[i];j++)
       cout<<"R";
       if(i!=b)
       cout<<"B";
    }
    cout<<endl;

}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    solve();
}