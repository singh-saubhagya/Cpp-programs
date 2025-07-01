#include<bits/stdc++.h>
using namespace std;
int main()
{
    char n;
    cin>>n;
    int ch=n;
    if(ch>=97 && ch<=122)
    {
        cout<<"character is lowercase \n";

    }
    else if(ch>=65 && ch<=90)
    {
        cout<<"character is uppercase \n";

    }
    else if (ch>=48 && ch<=57)
    {
        cout<<"character is integer from 0 to 9 \n";
    }
    else
    {
     cout<<"can't determined which character \n";

    }
}