#include<bits/stdc++.h>
using namespace std;
pair<int,int> findmax_min(int arr[],int n)
{
  int max,min;
  max=min=arr[0];
  for(int i=1;i<n;i++)
  {
    if(arr[i]>max)
    max=arr[i];
    else if(arr[i]<min)
    min=arr[i];
  }
  pair<int ,int>p ={max,min};
  return p;

}
int main()
{
  int size;
  cin>>size;
  int arr[1000];
  for(int i=0;i<size;i++)
  {
    cin>>arr[i];
    cout<<endl;
  }
  pair<int,int> p=findmax_min(arr,size);
  cout<<"Maximum in the array is"<<'\t'<<p.first<<endl<<"Minimum in the array is "<<'\t'<<p.second<<endl;


}

   
