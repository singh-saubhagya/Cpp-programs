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
/* In the quick sort we select an element at the first index(The positon is called  pivot) 
and place it at that postiton where the elements on its left side are smaller and on its right side are larger 
Here we don't need an auxillary space.
here's how we are finding the positon of the pivot..
we take the pivot and compare it with the elements in the front and if the element say x is smaller than the pivot we need some tranfer 
we place the element x at the pivot positon and at the xth index we place the element having index pivot + 1 
and at pivot + 1 index we place our old pivot element .
and increase the pointer of pivot by 1  
*/

void quicksort(vector <int> &v,int a,int b)
{
  if(a>=b)
  return;
  int pivot=a;
  for(int i=a;i<=b;i++)
  {
    if(v[pivot]>v[i])
    {

      int temp=v[pivot];
      v[pivot]=v[i];
      v[i]=v[pivot+1];
      v[pivot+1]=temp;
      pivot++;
    
    }
  }
  quicksort(v,a,pivot);
  quicksort(v,pivot+1,b);
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
    quicksort(v,0,n-1);
    cout<<endl<<"Sorted array :";
    printarray(v,n);      
}