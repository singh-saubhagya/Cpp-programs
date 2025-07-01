#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,two=1,dec=0,rem;
    cin>>n;
    while(n!=0)
    {
        rem=n%10;
        dec=dec+rem*two;
        two=two*2;
        n=n/10;
    }
    cout<<dec;
}