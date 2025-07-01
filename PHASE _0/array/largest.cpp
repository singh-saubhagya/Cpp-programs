#include<bits/stdc++.h>
using namespace std;
//optimal solution
//O(n) for the optimal solution
int findlargest(vector <int> &v,int n)
{
  int max=v[0];
  for(int i=1;i<n;i++)
  {
    if(v[i]>max)
    {
      max=v[i];
    }
    
  }
  return max;
}
//in the brute force solution we sort the array and print the element at the n-1 index.
//here in the brute force it takes O(nlogn) time complexity
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
  largest= findlargest(v,n);
  cout<<endl<<"The largest element in the array is "<<largest<<endl;
}