#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int j=1;j<=n;j++)
    {

    
    for(int i=1;i<=j;i++)
    {
        if(i*i==j)
        {
            cout<<j<<". "<<i;
            break;

        }
        else if(i*i>j)
        {
            cout<<j<<". "<<i-1;
            break;

        }
    }    
    cout<<"\n";
    }
}