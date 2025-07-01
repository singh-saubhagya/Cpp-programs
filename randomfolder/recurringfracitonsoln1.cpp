#include<bits/stdc++.h>
using namespace std;
#define tab '\t'
vector<int> v;
vector <string> result;

string solve(long long a,long long b)
{
    if(a==0)
    {
        string str="0";
        return str;
    }
    // long longa,b;
    // cin>>a>>b;
    long long sign=0;
    
    if((a<0)^(b<0))
    {
        sign=1;
    }
    a=abs(a);
    b=abs(b);
    long long x=a/b;
    double z=((double)a)/b;
    double c=((double)a)/b;
    z=z-x;
    string temp=to_string(c);
    string temp2=to_string(x);
    // long longposition=temp.find('.');
    // long longlength=temp.length();
    // if(position!=temp.length())
    // string frac=temp.substr(position,length-position);
    long long count2;
    if(x==0)
    {
        count2=0;
    }
    else
    count2=temp2.size();
    long long count=6-count2;
    long long pn;
    long long y=a%b;
    long long size=0;
    long long st=0,en=0;
    string str;
    if(a%b!=0)// if(x!=c) it is wrong cond !
    {

        while(1)
    {
        v.push_back(y);
        size++;
        y=y*10;
        y=y%b;
        if(y==0)
        {
            break;
        }
        auto it=find(v.begin(),v.end(),y);
        if(it!=v.end())
        {
            pn=it-v.begin()+1;
            st=pn;
            en=size;
            break;
        }

    }

    if(sign==1)
    str.push_back('-');
    str=str + to_string(x);
    str.push_back('.');
    if(st!=0)
    {
        
    
        for(long long i=1;i<=en;i++)
        {
            if(i==st)       
            {
                str.push_back('(');
            }
            
                long long w=(v[i-1]*10)/b;
                char ch='0' + w;
                str.push_back(ch); 
        }
    str.push_back(')');
    }
    else
    {
    long long n=a%b;
    while(n>0)
    {
        long long x=(n*10)/b;
        char ch='0'+x;
        str.push_back(ch);
        n=(n*10)%b;
    }
    

    }
   }
    else
    {
    if(sign==1)
    str.push_back('-');
    str=str + to_string(x);

    }
    return str;
}
signed main()
{
    long long q=20;
    // cin>>q;
    while(q--)
    {
      
      
      long long a=rand()%100;
      long long b=rand()%100+1;
      string str=  solve(a,b);
      cout<<str<<tab<<a<<tab<<b<<endl;
      v.clear();
      
     
    }
    // cout<<endl;
    // for(string str:result)
    // {
    //     cout<<str<<endl;
    // }
}