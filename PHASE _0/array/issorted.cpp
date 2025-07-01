#include <bits/stdc++.h>
using namespace std;

/*
in the brute force solution we take each element and check all its future  element
 whether those elements are greater than that element(asending order)*/




/*
This is the optimal solution where in single traversal we checked whether the given array is sorted or not .
We are checking in the alternate elements.
*/
bool issorted(vector <int> &v,int n)
{
    bool flag =true;
    for(int i=0;i<n-1;i++)
    {
        if(v[i]>v[i+1])
        {
        flag=false;
        break;
        }
    }
    return flag;
}
int main()
{
  int n,x;
  bool flag;
  vector <int> v;
  cout<<endl<<"enter the size of the array"<<endl;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cout<<endl<<"enter the element at the "<< i <<'\t'<<"index"<<endl;
    cin>>x;
    v.push_back(x);
  }
  flag=issorted(v,n);
  if(flag==true)
  cout<<endl<<"The array is sorted and is in asending order"<<endl;
  else
  cout<<endl<<"The array is not sorted "<<endl;
}
