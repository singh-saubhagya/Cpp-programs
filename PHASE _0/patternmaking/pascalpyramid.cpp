#include<bits/stdc++.h>
using namespace std;

struct pattern{
    int row,col;
};
int findsum(int i,int j,int n)
{
    if((i+(j/2)<n-1 || i<j/2+1-n))
    {
        return 0;
    }
    else if((i+(j/2)==n-1&& i==j/2+1-n))
    return 1;
    int sum;
    sum=findsum(i-1,j-2,n) + findsum(i-1,j+2,n);
    return sum;
}
void printpattern(int n,int m,int i,int j)
{
    
    if((i+(j/2)>=n-1&& i>=j/2+1-n) && j%2==0 )
        {   
            int sum=findsum(i,j,n);  
            if(sum==0)
            cout<<" ";
            else
            cout<<sum;
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
            for(int j=0;j<4*(n-1)+1;j++)
            {
                printpattern(n,n,i,j);
            }
            cout<<endl;
        }
        cout<<endl;

    }
}

//    0123456789      
//         *
//       * * *
//     * * * * *
//   * * * * * * *
// * * * * * * * * *

//         1     output
//       1   1
//     1   2   1
//   1   3   3   1
// 1   4   6   4   1

//         1   
//       1   1   
//     1   2   1   
//   1   3   3   1   
// 1   4   6   4   1  
