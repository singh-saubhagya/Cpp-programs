#include<bits/stdc++.h>
using namespace std;

/*
in the brute force solution we are just performing linear search

in the better solution we are just using map data structure or we can use array also but for that  
case we need to find the maximum element and create an array of size max+1

in the optimal solution (given below) we just taking xor of all the elements in the array since every duplicate element
is present twice hence the taking xor will make it zero and thus at last the no with the one freq will remain.

*/
int nowiththefreqone(vector <int> &v,int n)
{
    int num=0;
    for(int i=0;i<n;i++)
    {
        num=num^v[i];
    }
    return num;
}

int main()
{
  int n,x;
  vector <int> v;
  cout<<endl<<"enter the size of the array"<<endl;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cout<<endl<<"enter the element at the "<< i <<'\t'<<"index"<<endl;
    cin>>x;
    v.push_back(x);
  }
  int num=nowiththefreqone(v,n);
  cout<<endl<<"The no which has only one frequency is "<<'\t'<<num<<endl;
}  