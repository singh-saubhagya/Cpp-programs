#include<bits/stdc++.h>
using namespace std;

// struct pattern{
//     int k=0;
// };
int ak;
void printpattern(int n,int m,int i,int j)
{
         if((i+(j/2)>=n-1&& i>=j/2+1-n) && j%2==0 )
        {      
            if(j<=2*n-2)
        {   (ak)++; cout<<ak;
            }
            else
            {ak--;
            cout<<ak;
            }

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
      ak=0;
        for(int i=0;i<n;i++)
        {  ak=0;
            for(int j=0;j<4*(n-1)+1;j++)
            {
                printpattern(n,n,i,j);
            }
                
            cout<<endl;
        }
        cout<<endl;

   
        }   
          }

