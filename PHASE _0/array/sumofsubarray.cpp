#include<bits/stdc++.h>
using namespace std;
/*
Here agian we are using contribution technique as we have to find the sum of all subarray 
i.e sum of all the elements in the subarray and taking sum again with all possible subarray
To do this any ith element will be in a subarray of opening i+1 times(before the ith element) and 
its closing(elements after ith elment) will be n-i times hence in total it will come (i+1)*(n-i) 
times.
 using this we have reduce the time complexity from n^2(no of sub arrays is n+1 C 2  ) to n 

*/
int subarray(vector<int> &v,int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=v[i] * (i+1) * (n-i);
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
  k=subarray(v,n);
  cout<<endl<<"The sum of all the subarrays in the array is"<<'\t'<<k<<endl;    
}