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
/*Approach  1
in this approach we are storing the first d element in the temporary array and perform rotation of first n-d elemenst
then we add each element of the temporary array to the original array at the last k no of index.

Time complexity is O(n)
Space complexity is O(d)
*/
void Lrotate(vector <int> &v,int n,int d)
{
    int k=0;
    vector <int> z;
    d=d%n;

    for(int i=0;i<d;i++)
    {
        z.push_back(v[i]);
    }
    for(int i=0;i<n-d;i++)
    {
        v[i]=v[i+d];
    }
    for(int i=n-d;i<n;i++)
    {
        v[i]=z[k];
        k++;
    }
    printarray(v,n);
}
/*approach 2 in this approach we use reverse algorithm to shift the array by k time  
1: Reverse the first k elements of the array

Step 2: Reverse the last n-k elements of the array.

Step 3: Reverse the whole array.
Time complexity is O(n)
Space complexity is O(1)

*/
void reverse(vector <int>&v ,int a,int b)
{
    int temp;
    while(a<b)
    {
        temp=v[a];
        v[a]=v[b];
        v[b]=temp;
        a++;
        b--;
    }

}
void LrotateBY_rvalgo(vector <int> &v,int n,int d)
{
    reverse(v,0,d-1);
    reverse(v,n-d-1,n-1);
    reverse(v,0,n-1);
    printarray(v,n);
}

int main()
{
  int n,x,d;
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
  cout<<endl<<"enter the no of places by which you want to rotate the array"<<endl;
  cin>>d;
  LrotateBY_rvalgo(v,n,d);
}
