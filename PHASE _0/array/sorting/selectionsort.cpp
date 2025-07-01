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
void selectionsort(vector <int> v,int n)
{
  int min,temp;
  for(int i=0;i<n;i++)
  {
    min=i;
    for(int j=i+1;j<=n-1;j++)
    {
      if(v[j]<v[min])
      min=j;
    }
    temp=v[i];
    v[i]=v[min];
    v[min]=temp;

  }
  cout<<endl<<"Sorted array :"<<endl;
  printarray(v,n);
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
    selectionsort(v,n);
       
}