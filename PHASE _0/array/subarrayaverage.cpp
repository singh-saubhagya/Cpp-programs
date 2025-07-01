#include<bits/stdc++.h>
using namespace std;

int subarrayavg(vector <int> & v, int n,int p, int q)
{
    double sum=0,avg;
    int count =0;
    for(int i=0;i<n;i++)
    {
        for(int en=i;en<n;en++)
        {
            sum=sum+v[en];
            avg=sum/(en-i+1);
            if(avg>=(p/q))
            count++;
        }
        sum=0;
    }
}


int main()
{
    int n,x,p,q;    
    vector<int> v;
    cout<<endl<<"input the size of the array"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
      cout<<endl<<"input the element at the "<<'\t'<<i<<'\t'<<"index"<<endl;
      cin>>x;
      v.push_back(x);   
    }
    cout<<endl<<"Enter the value of p and q"<<endl;
    cin>>p>>q;
    subarrayavg(v,n,p,q);
}