#include<bits/stdc++.h>
using namespace std;
int main()
{
    int *arr[3];
    for(int i=0;i<3;i++)
    {
        arr[i]=new int [3];
        for(int j=0;j<3;j++)
        {
           
           cin>>arr[i][j] ;
        }
        
        
    }

     for(int i=0;i<3;i++)
    {
        cout<<endl;
        for(int j=0;j<3;j++)
        {
            cout<<arr[i][j]<<'\t';
        }
        cout<<endl;
    }
}