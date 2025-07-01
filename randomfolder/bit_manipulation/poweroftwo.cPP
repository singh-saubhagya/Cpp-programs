#include<bits/stdc++.h>
using namespace std;
int main()
{
    double n;
    cin>>n;
    bool flag=0;
    for(int i=0;i<=30;i++)
    {
        if(n==pow(2,i))
        {
            flag=1;
            break;
        }
    
    }
    if( flag==1)
    cout<<"The no can be represented in the power of two's";
    else 
    cout<<"the no can't be represented in the power of two";
}