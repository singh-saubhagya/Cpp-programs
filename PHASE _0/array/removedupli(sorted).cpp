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

brute force soln
declare the set and store each element in it while traversing the array;


optimal soln
Here the array is sorted and we have to remove all the duplicates in it .
For this we have traverse the array and use a variable named pn to place the unique elements.
Since the array is sorted the duplicated will be at the adjacent position so till we continuously get duplicated while traversing 
the array we don't increment the pn. and as soon as we get an unique element we place it at the pn index and increment it by 1.
Time complexity is O(n)
Space complexity is O(1)
it is also called 2 pointer approach one pointer to traverse the array and the other for pn

*/
void removeduplicates(vector <int> &v,int n)
{

 int pn=1;
 for(int i=1;i<n;i++)
 {
    if(v[i]!=v[i-1]) 
    {
        v[pn]=v[i];
        pn++;
    }
 
 }
   printarray(v,pn);


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
  removeduplicates(v,n);
}