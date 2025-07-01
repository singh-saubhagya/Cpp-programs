#include<bits/stdc++.h>
using namespace std;
int findlargest(vector <int> &v,int n,int max)
{
  if(n<0)
  return max;
    if(v[n]>max)
    {
      max=v[n];
    }
    
  
  findlargest(v,n-1,max);
}
int main()
{
  int n,x,largest;
  vector <int> v;
  cout<<endl<<"enter the size of the array"<<endl;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cout<<endl<<"enter the element at the "<< i <<'\t'<<"index"<<endl;
    cin>>x;
    v.push_back(x);
  }
  largest= findlargest(v,n-2,v[n-1]);
  cout<<endl<<"The largest element in the array is "<<largest<<endl;
}
