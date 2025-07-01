#include<bits/stdc++.h>
using namespace std;
int a=-1;
int snakehead=1;
void printpattern(int n,int m,int i,int j)
{
        if(i%2==1)
        {
            cout<<'#';
            
        }
        else
        {
            if(snakehead==j)
            {
                cout<<'#';
            }
            else
            cout<<'.';
        }
                   
            
          
}


int main()
{

  int n,m;
    cin>>n>>m;
    
        for(int i=1;i<=n;i++)
        {
            if(i%2==1)
            {if(snakehead==1)
            snakehead=m;
            else
            snakehead=1;}
            for(int j=1;j<=m;j++)
            {
                printpattern(n,m,i,j);
            }
            cout<<endl;
        }
        

//     }
 }