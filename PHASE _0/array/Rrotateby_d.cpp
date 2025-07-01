#include<bits/stdc++.h>
using namespace std;
void printarray(vector<int> v,int n)
{
   cout<<endl;
   for(int i=0;i<n;i++)
   {
     cout<<v[i];
   }
   cout<<endl;
}
void reverse(vector <int> &v, int a ,int b)
{
    while(a<b)
    {
        int temp=v[a];
        v[a]=v[b];
        v[b]=temp;
        a++;
        b--;
    }
}
void rotateright(vector <int> &v,int n,int d)
{
    d=d%n;
    reverse(v,n-d,n-1);
    reverse(v,0,n-d-1);
    reverse(v,0,n-1);
    printarray(v,n);

}

int main()
{
  int n,d,x;
  vector <int> v;
  cin>>n;
  cin>>d;

  for(int i=0;i<n;i++)
  {
    cin>>x;
    v.push_back(x);
  }
  rotateright(v,n,d);
}