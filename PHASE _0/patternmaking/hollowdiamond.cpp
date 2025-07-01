//     *
//    * *
//   *   *
//  *     *
// *       *
//  *     *
//   *   *
//    * *
//     *


//     *
//    * *
//   *   *  
//  *     *
// *       *
//  *     * 
//   *   *
//    * *
//     *
#include<bits/stdc++.h>
using namespace std;

void printpattern(int n,int m,int i,int j)
{
    if(i==-1*j +n-1|| i==j+n-1|| i== -j + 3*n-3 || i == j-(n-1))
    {
        cout<<'*';

    }
    else
    cout<<' ';
}
 

int main()
{
    int x,n,m;
    cin>>x;
    vector <int> arr;
    for(int k=0;k<x;k++)
    {
        int p;

        cin>>p;
        arr.push_back(p);
    }
    for(int k=0;k<x;k++)
    {
       int  n=arr[k];
       
       
        for(int i=0;i<2*n-1;i++)
        {
            for(int j=0;j<2*(n)-1;j++)
            {
                printpattern(n,n,i,j);
            }
            cout<<endl;
        }
        cout<<endl;

    }
}
