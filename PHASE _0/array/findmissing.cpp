#include<bits/stdc++.h>
using namespace std;
/*
 Problem statement:The array has the size n with elemenst ranging from 1 to n+1 and we have to find the missing no.


 1.   For the brute force approach we just perfom linear search in the vector v.

 2.   Below is the optimal solution for the problem where we are taking sum of elements of the array
      and subtracting with the sum of first n+1 numbers.
      Time complexity is O(n) and space complexity is O(1).

      Another optimal solution is using xor between all the elements in the array and taking xor 
      with all the no ranging from 1 to n+1.

 3.   We can also solve this problem using map by storing the frequency but it will increase the space complexity to O(n).     
    
*/
int findmissing(vector <int> &v,int n)
{

    int sum=0,num=0;
    for(int i=0;i<n;i++)
    {   
        sum=sum+v[i];
    }

    for(int j=1;j<=n+1;j++)
    {
        num=num+j;
    }
    
    return num-sum;

}

int findmissing(vector <int> &v,int n)
{
    map <int,int> m;
    for(int i=0;i<n;i++)
    {
        m[v[i]]=1;
    }
    for(int i=1;i<=n+1;i++)
    {
        if(m.find(i)==m.end())
        {
            return i;
        }
    }
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
 int num=findmissing(v,n);
 cout<<endl<<"The missing no in the array is "<<'\t'<<num<<endl;
   
}