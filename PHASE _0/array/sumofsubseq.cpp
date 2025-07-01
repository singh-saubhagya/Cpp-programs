#include<bits/stdc++.h>
using namespace std;

/*
using contribution technique which is finding the sum coloumn wise and not row wise as in the 
row wise it will take 2^n rows while in the coloumn wise it will take only n times.
for the subsequence any element will come 2^n-1 times in all the subsequence of the array of size n
because for the remaining n-1 elements we have 2 choices either take it or leave it.
 
*/
int sumofsubseq(vector <int> &v,int n)
{
    double sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=v[i]*pow(2,n-1);
    }
    return sum;
}
int main()
{
  int n,x,k;
  vector <int> v;
  cout<<endl<<"enter the size of the array"<<endl;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cout<<endl<<"enter the element at the "<< i <<'\t'<<"index"<<endl;
    cin>>x;
    v.push_back(x);
  }
  k=sumofsubseq(v,n);
  cout<<endl<<"The sum of all subsequence of the array is"<<'\t'<<k<<endl;
}