#include<bits/stdc++.h>
using namespace std;
int main()
{
int a,b,div,rem,d;
cin>>a>>b;
d=a;
div=b;

while( d!=0)
{
    rem=div%d;
    div=d;
    d=rem;
}
cout<<div;

}