#include <bits/stdc++.h>
using namespace std;

//Compiler version g++ 6.3.0
void printarray(vector<int> v,int n)
{
   cout<<endl;
   for(int i=0;i<n;i++)
   {
     cout<<'\t'<<v[i];
   }
   cout<<endl;
}
/*
void bubblesort(vector <int> &v,int n,int i)
{
    if(i==n)
    return;
    int temp;
    for(int j=i;j<=n-1;j++)
    {
      if(v[j]<v[j+1])
      {
       temp=v[j];
       v[j]=v[j+1];
       v[j+1]=temp;
      }
    }
  bubblesort(v,n,i+1);
 
}*/
void bubblesort(vector <int> &v,int n)
{
    if(n==1)
    return;
    int temp;
    for(int j=0;j<=n-1;j++)
    {
      if(v[j]<v[j+1])
      {
       temp=v[j];
       v[j]=v[j+1];
       v[j+1]=temp;
      }
    }
  bubblesort(v,n-1);
 
}

int main()
{
    int n,x;
    
    vector<int> v;
    cout<<endl<<"input the size of the array"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
      cout<<endl<<"input the element at the "<<'\t'<<i<<'\t'<<"index";
      cin>>x;
      v.push_back(x);   
    }
    cout<<endl<<"Original array :";
    printarray(v,n);
    bubblesort(v,n-1);
    cout<<endl<<"Sorted array :"<<endl;
    printarray(v,n);
     
       
}
