#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void rec(vector<vector<int>> &arr,int level,int n,int &ct,int st,int en)
{
    if(level==n)
    {
        ct++;
        return;
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(arr[i][j]==0)
            {
                int x=abs(i-st);
                int y=abs(j-en);
                if(x==0 && y==1)
                {
                    level++;
                    arr[i][j]=1;
                    rec(arr,level,n,ct,i,j);
                    level--;
                    arr[i][j]=0;
                }
                else if(x==1 && y==0)
                {
                    level++;
                    arr[i][j]=1;
                    rec(arr,level,n,ct,i,j);
                    level--;
                    arr[i][j]=0;
                }
                else if(x==0 && y==2)
                {
                    int a=i;
                    int b=(j+en)/2;
                    if(arr[a][b]==1)
                    {
                        arr[i][j]=1;
                        level++;
                        rec(arr,level,n,ct,i,j);
                        level--;
                        arr[i][j]=0;
                    }
                }
                else if (x==2 && y==0)
                {
                    int a=(i+st)/2;
                    int b=en;
                    if(arr[a][b]==1)
                    {
                        arr[i][j]=1;
                        level++;
                        rec(arr,level,n,ct,i,j);
                        level--;
                        arr[i][j]=0;
                    }
                }
                else if (x==1 && y==1)
                {
                    level++;
                    arr[i][j]=1;
                    rec(arr,level,n,ct,i,j);
                    level--;
                    arr[i][j]=0;
                }

                else if(x==1 && y==2)
                {
                    level++;
                    arr[i][j]=1;
                    rec(arr,level,n,ct,i,j);
                    level--;
                    arr[i][j]=0;
                }
                else if (x==2 && y==1)
                {
                    level++;
                    arr[i][j]=1;
                    rec(arr,level,n,ct,i,j);
                    level--;
                    arr[i][j]=0;
                }

                else if(x==2 && y==2)
                {
                    int a=(i+st)/2;
                    int b=(j+en)/2;
                    if(arr[a][b]==1)
                    {
                        level++;
                        arr[i][j]=1;
                        rec(arr,level,n,ct,i,j);
                        level--;
                        arr[i][j]=0;
                    }
                }
                
                
            }
        }
    }
}
signed main()
{
    int n;
    cin>>n;
    vector<vector<int>> arr;
    arr.assign(3,vector<int>(3,0));
    int ct=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
             arr[i][j]=1;
             rec(arr,1,n,ct,i,j);
             arr[i][j]=0;// backtraking 
        }
    }
    cout<<ct<<endl;
}