

/*
 p is the size of block with / \ and .
 n is no of times that block is going to repeat row wise
 m is no of times that block is going to repeat col wise
 each block of edge p(square in shape ) is surrounder by stars
 rows:p*n+n+1
 col:p*m+m+1
 for / and \ use eqn of line 
 . in the else case
pattern(Monomer) is going to repeat after 2p+2 times in both col and rol wise
* is there are every end or beginning of block i.e at the p+1 index both col and row wise



*/
struct input{
    int a,b,c;
};

#include<bits/stdc++.h>
using namespace std;


void printpattern(int n,int m,int i,int j,int p)
{



// 3 1 3


// *****
// *\..*
// *.\.*
// *..\*
// *****
// *../*
// *./.*
// */..*
// *****
// *\..*
// *.\.*
// *..\*
// *****


// *****
// *\*\*
// *****
// *\*\*
// *****
// *\*\*
// *****
// *\*\*
// *****
// *\*\*
// *****
// *\*\*
// *****



    if(i%(p+1)==0||j%(p+1)==0)
    cout<<'*';
    else
    {
        if(i==j)
        cout<<'\\';
        else if(i==-j+2*(p+1))
        cout<<'/';
        else
        cout<<'.';
    }
    
}
 

int main()
{
    
    int x,n,m;
    cin>>x;
    vector<input> arr;
    for(int k=0;k<x;k++)
    {
        input p;
        cin>>p.a>>p.b>>p.c;
        arr.push_back(p);
    }
    for(int k=0;k<x;k++)
    {
       input temp  =arr[k];
       int n=temp.a;
       int m=temp.b;
       int p=temp.c;
       
       
        for(int i=0;i<p*n + n+1;i++)
        {
            for(int j=0;j<p*m + m+1;j++)
            {
             printpattern(n,m,i%(2*p+2),j%(2+p*2),p); 
            }
            cout<<endl;
        }
        cout<<endl;

    }
}
