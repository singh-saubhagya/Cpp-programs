#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
int arr[100006];
int t[400012];


void addnumber(int id,int l,int r,int x)
{
    int mid=l+(r-l)/2;
    if(l==r)
    {
        t[id]=1;
        arr[x]=1;
        return ;
    }
    if(x<=mid)
    {
        addnumber(id<<1,l,mid,x);
      
    }
    else 
    {
        addnumber(id<<1|1,mid+1,r,x);
    }
    t[id]=t[id<<1]+t[id<<1|1];
    return ;
}
 void removenumber (int id,int l,int r,int x)
 {
    int mid=l+(r-l)/2;
    if(l==r)
    {
        t[id]=0;
        arr[x]=0;
        return ;
    }
    if(x<=mid)
    {
        removenumber(id<<1,l,mid,x);
    }
    else 
    {
        removenumber(id<<1|1,mid+1,r,x);
    }
    t[id]=t[id<<1]+t[id<<1|1];
    return ; 
 }
int answerquery(int id,int l,int r,int k)
{
    int mid=l+(r-l)/2;
    if(l==r)
    return l;
    if(t[id<<1]>=k)
    {
        return answerquery(id<<1,l,mid,k);
    }
    else 
    {
        return answerquery(id<<1|1,mid+1,r,k-t[id<<1]);
    }

}
void solve()
{
    memset(arr,0,sizeof(arr));
    memset(t,0,sizeof(t));
    int q;
    cin>>q;
    while(q--)
    {
        char ch;
        cin>>ch;
        int x;
        cin>>x;
        if(ch=='+')
        {
            addnumber(1,0,100000,x);
        }
        else if(ch=='-')
        {
            removenumber(1,0,100000,x);
        }
        else 
        {
            cout<<answerquery(1,0,100000,x)<<endl;
        }
    }
}
signed main()
{
  cin.tie(0); cout.tie(0);
  solve();
}