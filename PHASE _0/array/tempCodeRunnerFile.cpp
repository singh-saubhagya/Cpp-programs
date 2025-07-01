#include<bits/stdc++.h>
using namespace std;
int main()
{
int a,b,div,rem,q;
cin>>a>>b;
q=a;
div=b;

while( q!=0)
{
    rem=div%q;
    div=q;
    q=rem;

    

}
cout<<div;

}