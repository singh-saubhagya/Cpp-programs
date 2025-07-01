// *************
// *..*..*..*..*
// *..*..*..*..*
// *************
// *..*..*..*..*
// *..*..*..*..*
// *************
// *..*..*..*..*
// *..*..*..*..*
// *************
// solu of comment part
// 3,4 no of * with dots = 4+1
// rows 10 col 13
// no of rows with full * is 3+1
// col=3m +1
// row =3n+1


/*
soln 2
finding monomer 
***
*..
and then using modulus for repetition
*/
#include<bits/stdc++.h>
using namespace std;

void printpattern(int n,int m,int i,int j)
{

    if(i==n-1)
    {cout<<'*';return;}
    else if(j==m-1)
    {cout<<'*';return ;}
    if(i%3==0|| j%3==0)
    cout<<'*';
    else
    cout<<'.';
        // if(i%3==0)
    // cout<<'*';
    // else
    // {
    //     if(j%3==0)
    //     {
    //         cout<<'*';

    //     }
    //     else
    //     cout<<'.';
    // }
}
 

int main()
{
    int x,n,m;
    cin>>x;
    vector <pair<int,int>> arr;
    for(int k=0;k<x;k++)
    {
        pair<int ,int> p;
        cin>>p.first>>p.second;
        arr.push_back(p);
    }
    for(int k=0;k<x;k++)
    {
       pair<int,int> temp  =arr[k];
       int n=temp.first;
       int m=temp.second;
       n=3*n+1;
       m=3*m+1;
       
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                printpattern(n,m,i,j);
            }
            cout<<endl;
        }
        cout<<endl;

    }
}
