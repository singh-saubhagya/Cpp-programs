#include<bits/stdc++.h>
using namespace std;

struct pattern{
    int row,col;
};

void printpattern(int n,int m,int i,int j)
{
        if(i==0|| j==0|| i==n-1 || j==m-1)
        {      
            cout<<'*';
        } 
        else
        cout<<" ";

}


int main()
{
    int x,n,m;
    cin>>x;
    vector <pattern> arr;
    for(int k=0;k<x;k++)
    {
        pattern p;

        cin>>p.row>>p.col;
        arr.push_back(p);
    }
    for(int k=0;k<x;k++)
    {
       pattern p=arr[k];
       n=p.row;
       m=p.col;
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