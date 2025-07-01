#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,bry=0,rem,ten=1;
    cin>>n;
    while(n!=0)
    {
        rem=n%2;
        n=n/2;
        bry=rem*ten+bry;
        ten=ten*10;
    }
    cout<<bry;
}