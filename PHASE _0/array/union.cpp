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
Other approaches
1. using set.
2. using 2 pointer





vector < int > FindUnion(int arr1[], int arr2[], int n, int m) {
  int i = 0, j = 0; // pointers
  vector < int > Union; // Uninon vector
  while (i < n && j < m) {
    if (arr1[i] <= arr2[j]) // Case 1 and 2
    {
      if (Union.size() == 0 || Union.back() != arr1[i])
        Union.push_back(arr1[i]);
      i++;
    } else // case 3
    {
      if (Union.size() == 0 || Union.back() != arr2[j])
        Union.push_back(arr2[j]);
      j++;
    }
  }
  while (i < n) // IF any element left in arr1
  {
    if (Union.back() != arr1[i])
      Union.push_back(arr1[i]);
    i++;
  }
  while (j < m) // If any elements left in arr2
  {
    if (Union.back() != arr2[j])
      Union.push_back(arr2[j]);
    j++;
  }
  return Union;
}


*/


/*
Optimal solution

In this approach we are using map.
in loop 1 we first  visit all the elements of the array 1 and add it to the map.
if conditon is used not to add element again in the unioned array.
in the second array we visit only those elements which are not added in the unioned array.

Thus if conditon takes care of the both duplicates using map and to know which elements are not visited.
 
Time complexity is O(n+m)
Space complexity is O(n+m)

*/

void findunion(vector <int> &v,int n,vector <int> &w,int m)
{
    map<int ,int> k;
    vector <int> z;
    int size=0;
    for(int i=0;i<n;i++)
    {
        if(k.find(v[i])==k.end())
        {
        k[v[i]]=1;
        z.push_back(v[i]);
        size++;
        }

    }   
    for(int i=0;i<m;i++)
    {
        if(k.find(w[i])==k.end())
        {
         k[w[i]]=1;
         z.push_back(w[i]);
         size++;
        }
    }
    printarray(z,size);
}
int main()
{
  int n,x,m;
  vector <int> v,w;
  cout<<endl<<"enter the size of the first array "<<endl;
  cin>>n;
  cout<<endl<<"enter the size of the second array "<<endl;
  cin>>m;
  cout<<endl<<"ARRAY 1"<<endl;
 for(int i=0;i<n;i++)
  {
    cout<<endl<<"enter the element at the "<< i <<'\t'<<"index"<<endl;
    cin>>x;
    v.push_back(x);
  }
 cout<<endl<<"ARRAY 2"<<endl;

  for(int i=0;i<m;i++)
  {
    cout<<endl<<"enter the element at the "<< i <<'\t'<<"index"<<endl;
    cin>>x;
    w.push_back(x);
  }
  findunion(v,n,w,m);
}