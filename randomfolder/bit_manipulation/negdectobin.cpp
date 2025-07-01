#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,ten=1,bry=0;
    cin>>n;
    
    while(n!=0)
    {
        int bit=(n&1);

        bry=bit*ten+bry;
        n=n>>1;
        ten=ten*10; 
    }
    cout<<bry;

}