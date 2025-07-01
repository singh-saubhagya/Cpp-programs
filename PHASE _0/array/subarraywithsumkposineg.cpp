
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
}
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
                
            }
            
        }
    }
    printarray(v,pn,size);
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