#include<bits/stdc++.h>
using namespace std;

/*
This is the most optimal solution to the problem with Time complexity O(n) and space complexity O(1)
In this solution we are just counting the consecutive no of 1's in the count variables and as soon as we get 
0 we check the value in the count varible with the previous count variable stored at the index n
if the new one is greater we update the value .
At last we return the value at the index n.

*/
int countones(vector <int> &v,int n)
{
    int count=0;
    v.push_back(0);
    for(int i=0;i<n;i++)
    {
        if(v[i]==1)
        count++;
        else
        {
          count=0;

          if(count>v[n])
            {
            v[n]=count;
            }
        }
           

    }
    if(count>v[n])
            {
            v[n]=count;
            }
    return v[n];
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
  int count=countones(v,n);
  cout<<endl<<"The max no. of consecutive 1's in the array are "<<'\t'<<count<<endl;
}