#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,k,j,x,a1,a2,z,flag,count,l,m,temp,a,k1;
    cin>>n;
    vector <int> v,v1;
    for(l=1;l<=n;l++)
    {
        v.clear();
        cin>>k;
        k1=0;

        for(m=0;m<k;m++)
        {
            cin>>x;
            v.push_back(x);
            if(m>=1)
            {
                
                    if(v[m]%2==0)
                    {
                     temp=v[m];
                     v[m]=v[k1];
                     v[k1]=temp;
                     k1++;
                    }
                    
            }
        }
    
        count=0;
        
        for(i=0;i<k-1;i++)
        {
            if(v[i]%2==0)
            {
                count=count+k-1-i;
            }
            else
            {
            for(j=i+1;j<k;j++)
            {
            long long x=__gcd(v[i],v[j]);
            if(x>1)
            {
                count++;
            }
            }
            }
        }
        v1.push_back(count);
    }
    for(int o:v1)
    {
        cout<<o<<"\n";
    }

}
