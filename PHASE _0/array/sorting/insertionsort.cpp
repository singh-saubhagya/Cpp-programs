#include <bits/stdc++.h>
using namespace std;
void printarray(vector<int> v,int n)
{
   cout<<endl;
   for(int i=0;i<n;i++)
   {
     cout<<'\t'<<v[i];
   }
   cout<<endl;
}
void insertionsort(vector <int> v,int n)
{
  int temp,pn;
  for(int i=1;i<n;i++)
  {
    pn=i;
    for(int j=i-1;j>=0;j--)
    {
      if(v[pn]<v[j])
      {
       temp=v[pn];
       v[pn]=v[j];
       v[j]=temp;
       pn=j;
      }
    }
    

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
    insertionsort(v,n);
       
}