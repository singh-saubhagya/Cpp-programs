#include<bits/stdc++.h>
using namespace std;

int linearsearch(vector <int> &v,int n, int num)
{
    for(int i=0;i<n;i++)
    {
        if(v[i]==num)
        return i;
    }    
    return -1;
}

int main()
{
  int n,x,num;
  vector <int> v;
  cout<<endl<<"enter the size of the array"<<endl;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cout<<endl<<"enter the element at the "<< i <<'\t'<<"index"<<endl;
    cin>>x;
    v.push_back(x);
  }
  cout<<endl<<"Enter the element to search"<<endl;
  cin>>num;
  int flag=linearsearch(v,n,num);
  if(flag>0)
  cout<<endl<<"The element is found at the index"<<'\t'<<flag<<endl;
  else
  cout<<endl<<"Element not found"<<endl;
}
