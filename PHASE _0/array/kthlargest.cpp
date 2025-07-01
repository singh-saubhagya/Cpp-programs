#include<bits/stdc++.h>
using namespace std;
void printarray(vector<int> v,int n)
{
   cout<<endl;
   for(int i=0;i<n;i++)
   {
     cout<<'\t'<<v[i];
   }
   cout<<endl;
}
/*
Time complexity is O(n*k) as break is present
*/
int klargest(vector<int> &v,int n,int k)
{
    vector<int> z;
    for(int i=0;i<k;i++)
    {
        z.push_back(-1);// to store indices of first k elements initially -1
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            if(z[j]==-1||v[i]>v[z[j]])
            {
                for(int m=k-1;m>=j+1;m--)
                {
                    z[m]=z[m-1];

                }
                z[j]=i;
                break;
                /*break is important because once the element of index  i is inserted at the correct positon we
                further don't need the j loop to run.
                */
             }


        }
    }
    return z[k-1];
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
    cout<<endl<<"Enter the value of k to find the kth largest element in the array"<<endl;
    cin>>k;
    int klarg=klargest(v,n,k);
    cout<<endl<<"The kth largest element in the array is "<<'\t'<<v[klarg]<<endl;
}