#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,k;
    cout<<"\nenter the no of elements\n";
    cin>>n;
    vector<int> v;
    for(i=1;i<=n;i++)
    {
        cout<<"\nenter the number\n";
        cin>>k;
        v.push_back(k);
    }
    sort(v.begin(),v.end());
    for(i=0;i<v.size();i++)
    {
        cout<<"\n"<<v[i];
    }


}