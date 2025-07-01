#include<bits/stdc++.h>
using namespace std;

struct pattern{
    int row,col;
};

void printpattern(int n,int m,int i,int j)
{
        if(i+j<=n-1)
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
    vector <int> arr;
    for(int k=0;k<x;k++)
    {
        int p;

        cin>>p;
        arr.push_back(p);
    }
    for(int k=0;k<x;k++)
    {
       int  p=arr[k];
       n=p;
       
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                printpattern(n,n,i,j);
            }
            cout<<endl;
        }
        cout<<endl;

    }
}