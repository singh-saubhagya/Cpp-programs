#include<bits/stdc++.h>
#include<Math.h>
using namespace std;
int main()
{
    int n;
    float lsb,binary=0,i=0;
    cin>>n;
    while(n!=0)
    {
        lsb=(n&1);
        binary=(lsb*(pow(10,i)))+binary;
        n=n>>1;
        i++;

    }
    


    cout<<binary;
}