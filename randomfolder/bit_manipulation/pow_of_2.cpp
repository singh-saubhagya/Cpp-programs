#include<bits/stdc++.h>
using namespace std;
int main()
{
    int  n,power=1;
    cin>>n;
    bool flag=0;
    for(int  i=0;i<=30;i++)
    {
        if(n==power)// or we can also use round(pow(2,i))
                    // as pow may return floating point integer which is very close to the true value
                    // therfore using round to round off to the nearest integer
        {
            flag=1;
            break;
        }
        power*=2;
    
    }
    if( flag==1)
    cout<<endl<<"YES";
    else 
    cout<<endl<<"NO";
}