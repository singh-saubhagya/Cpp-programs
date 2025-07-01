#include<bits/stdc++.h>
using namespace std;
void printarray(vector<int> v,int a,int b)
{
   cout<<endl;
   for(int i=a;i<a+b;i++)
   {
     cout<<'\t'<<v[i];
   }
   cout<<endl;
}/*
This is the brute force solution of the problem where we are using two loops.The outer loop pointer of 
the loop tells us from where the subarray is start and the inner loop pointer gives us further
elements for summing up the elements.

The sum is added to the sum variable and if the sum becomes equal to the desired sum we save the length
of the array and then use break. If somehow the sum is greater than the desired sum we again use break.
 int longestsubarray(vector <int> &v,int n,int k)
 {
    int sum,size=0,pn;
    for(int i=0;i<n;i++)
    {
        sum=v[i];
        if(sum==k)
        {
            pn=i;
            size=1;
            break;
        }
        for(int j=i+1;j<n;j++)
        {
            sum=sum+v[j];
            if(sum==k)
            {
                if(size<j-i+1)
                {
                    size=j-i+1;
                    pn=i;
                }
                break;
            }
            else if(sum>k)
            {
                break;
            }
        }
    }
    printarray(v,pn,size);
    }
    */
 /*
 This is the most optimal solution to the problem where we are just traversing the array and doing the sum of
 each element. 
 The pn pointer is used to record the position of the subarray from where it has started
 As soon as the sum becomes equal to the desired sum we save the starting index and the 
 length of the subarray.
 When the sum becomes greater than the desired sum ,we increase the pn pointer which indicates new subarray is staring
 from the pn+1 position and accordingly we update the sum variable and count variable

 When the sum becomes equal to the desired ,we increase the pn pointer which indicates new subarray is staring
 from the pn+1 position and accordingly we update the sum variable and count variable
 we are doing this because we want to search for a new subarray whose size is greater than this one.

 Time complexity is O(n)
 Space complexity is O(1)
 */
  int longestsubarray(vector <int> &v,int n,int k)
  {
    unordered_map<int,int> m;
    int sum=0,pn=0;
    int count=0;
    int savecount=0;
    int index=pn;
    for(int i=0;i<n;i++)
    {
      sum =sum+v[i];
      count++;
      while(sum>k)//Using while loop as removal of the first element of the may not necessarly make the sum lesser than k
      {
        sum=sum-v[pn];
        count--;
        pn++;
      }
      if(sum==k)
      {
        if(count>savecount)
        {
        savecount=count;
        index=pn;
        
        }
        sum=sum-v[pn];
        pn++;
        count--;
        
      }
    }
    printarray(v,index,savecount);  
    
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
  cout<<endl<<"Enter the sum"<<endl;
  cin>>k;
  longestsubarray(v,n,k);
  
}