#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,neg;
    cin>>n;
    neg=~n;
    int k=0;
    while(n!=0)
    {
        k=k<<1;
        k=k|1;
        n=n>>1;
    }
    neg=neg&k;
    cout<<neg;


}