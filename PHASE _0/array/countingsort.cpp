#include<bits/stdc++.h>
using namespace std;
void countsort(vector <int> &v,int n)
{
    int max=-1;
    vector <int> z;
    for(int i=0;i<n;i++)
    {
        if(max==-1||v[i]>v[max])
        max=i;
        
    }
    for(int i=0;i<=v[max];i++)
    {
        z.push_back(0);
    }
    for(int i=0;i<n;i++)
    {
        z[v[i]]++;
    }
    for(int i=0;i<=v[max];i++)
    {
        while(z[i]>0)
        {
        cout<<" "<<i<<"";
        z[i]--;
        }
    }
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
  countsort(v,n);
}