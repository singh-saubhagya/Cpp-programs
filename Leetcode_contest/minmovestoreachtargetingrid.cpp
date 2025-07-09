
#include<bits/stdc++.h>
using namespace std;


pair<int,int> findprev(int i,int j)
{
    if(i>=j)
    {
        if((i&1)==0)
        {
            int a=i/2;
            if(a>=j)
            return {a,j};
        }
        
        
        int a=i-j;
        if(j>=a)
        return {a,j};
        
    }
    else 
    {
        if((j&1)==0)
        {
            int b=j/2;
            if(b>=i)
            return {i,b};
        }
        int b=j-i;
        if(i>=b)
        return {i,b};
    }
    return {-1,-1};
}
int minMoves(int   sx, int  sy, int  tx, int  ty)
{
    int ct=0;
    bool flag=false ;

    if(tx==sx && ty==sy)
    return 0;
    else 
    {
        if(sx==0 && sy==0)
        return -1;
    }
    while(tx>=sx && ty>=sy)
    {
        
       pair<int,int> p= findprev(tx,ty);
       ct++;
        
       if(p.first==sx && p.second==sy)
      {
        flag=true;
        break;
      }
       tx=p.first;
       ty=p.second;
    }
    if(flag)
    return ct;
    else return -1;
    
}

signed main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
   cout<<minMoves(a,b,c,d);
    
}