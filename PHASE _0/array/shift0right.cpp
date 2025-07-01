#include<bits/stdc++.h>
using namespace std;
/*
Here again we are using the two pointer approach one pointer to traverse the array
and the other to place the non zero element.
As we progress with the traversing of the array we count the no of 0's in the counter variable.

The pointer variable pn(initialized with 0) is used for the positioning of non zero elements.
When we get non zero element we placeit at the pn index and increase the pointer by 1.
Thus all the non zero element are consequently placed in the array.

For zeros we use an another for loop to insert at the right index.
Time complexity is O(n)
Space complexity is O(1)



here is one more version of solving this problem usign double pointer

for(int i=0;i<n;i++)
{
    if(v[i]==0)
    {
    j=i;
    break;
    }
}

for(int i=j+1;i<n;i++)
{
    if(v[i]!=0)
    {
        swap(v[i],v[j]);
        j++;
    }
}



*/
void printarray(vector<int> v,int n)
{
   cout<<endl;
   for(int i=0;i<n;i++)
   {
     cout<<'\t'<<v[i];
   }
   cout<<endl;
}
void shiftzeros(vector <int>&v,int n)
{
    int pn=0,count=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]==0)
        {
            count++;
            continue;
        }

        v[pn]=v[i];
        pn++;
        
    }
    for(int i=1;i<=count;i++)
    {
        v[n-i]=0;
    }

    printarray(v,n);
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
  shiftzeros(v,n);
}
