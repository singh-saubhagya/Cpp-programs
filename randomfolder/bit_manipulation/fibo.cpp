#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,flag=0,sum=0;
    cin>>n;
    vector <int> v;
    v.push_back(0);
    v.push_back(1);
    for(i=3;flag!=n;i++)
    {
        sum=v[i-1]+v[i-2];
        v.push_back(sum);
        flag=sum;
    }
    i--;
    
}
