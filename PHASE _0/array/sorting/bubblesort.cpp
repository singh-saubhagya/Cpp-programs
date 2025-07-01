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
void bubblesort(vector <int> &v,int n)
{
  int temp;
  for(int i=n-1;i>=0;i--)// we can also start loop from i=0 to n-1 but then in inner loop we have to start making comparisons from the right most index. 
  {
    
    for(int j=0;j<=i-1;j++)
    {
      if(v[j]>v[j+1])
      {
       temp=v[j];
       v[j]=v[j+1];
       v[j+1]=temp;
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
    bubblesort(v,n);
    printarray(v,n);
     
       
}