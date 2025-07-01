# include <bits/stdc++.h>
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

/*in merge sort we divide the array and then recursively divide the resultant array 
 after dividing at the lowest level i.e. when we have 2 element in the array..
we place them in correct positons and further correcting at each upper levels
To place in the corrected positons we need an auxillary space here we have taken a vector z .
The contents of vector z are then copies to the original vector.
*/
void msort(vector<int>& v,int midpn,int a,int b)
{
  
  vector <int> z;
  int m=midpn+1;
  int start=a;
  
  while(a<=midpn && m<=b)
  {
  if(v[a]<v[m])
  {
  z.push_back(v[a]);
  a++;  
  }
  else
  {
  z.push_back(v[m]);

  m++;
  }
  
  }
  while(m <= b)
    {
      {   
      z.push_back(v[m]);
      m++;
      
      }
    }
    while(a <= midpn)
    {
        z.push_back(v[a]);
        a++;
      
    }  for(int i=b;i>=start;i--)
   {
     v[i]=z.back();
     z.pop_back();
   }
  
}
void merge(vector <int>& v, int a,int b)
{
  if(a>=b)
  return;
  int midpn;
  midpn=(b-a)/2+a;
  merge(v,a,midpn);
  merge(v,midpn+1,b);
  msort(v,midpn,a,b);

  
}
int main()
{
    int n,x; 
    vector<int> v,z;
    cout<<endl<<"input the size of the array"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
      cout<<endl<<"input the element at the "<<'\t'<<i<<'\t'<<"index";
      cin>>x;
      v.push_back(x);   
    }
    cout<<endl<<"Original array :";
    printarray(v,n);
    merge(v,0,n-1);
    cout<<endl<<"Sorted array :"<<endl;
    printarray(v,n);
       
}