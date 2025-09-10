#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
const int inf=1e9;vector<int> arr;
struct node{
    int mval;
    int mx;
    int smx;
    node()
    {
        mval=-inf;
        mx=-inf;
        smx=-inf;
    }
};
node t[800010];
int n;
node combine(int id1,int id2)
{
    int mx;
    int smx;
    if(t[id1].mx>t[id2].mx)
    {
        mx=t[id1].mx;
        if(t[id1].smx!=-1)
        {
          smx=max(t[id2].mx,t[id1].smx);
        }
        else 
        {
          smx=t[id2].mx;
        }
    }
    else 
    {
        mx=t[id2].mx;
        if(t[id2].smx!=-1)
        {
          smx=max(t[id2].smx,t[id1].mx);
        }
        else 
        {
          smx=t[id1].mx;
        }
    }
    int sum=mx+smx;
    node temp;
    temp.mval=sum;
    temp.mx=mx;
    temp.smx=smx;
    return  temp; 
}
void build(int id,int l,int r)
{
    if(l==r)
    {
        node temp;
        temp.mval=arr[l];
        temp.mx=arr[l];
        temp.smx=-1;
        t[id]=temp;
        return ;
    }
    int mid=l+((r-l)>>1);
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    t[id]=combine(id<<1,id<<1|1);
}
void update(int id,int l,int r,int val,int i)
{
    if(i<l || i>r)
    return ;
    if(l==r)
    {
        arr[l]=val;
        node temp;
        temp.mval=arr[l];
        temp.mx=arr[l];
        temp.smx=-1;
        t[id]=temp;
        return ;
    }
   int mid=l+((r-l)>>1);
    update(id<<1,l,mid,val,i);
    update(id<<1|1,mid+1,r,val,i);
    t[id]=combine(id<<1,id<<1|1);
    return ;
}
pair<int,int> findanswer(pair<int,int> a,pair<int,int> b)
{
    
    int amx=a.first;
    int bmx=b.first;
    int fmx,fsmx;
    int asmx=a.second;
    int bsmx=b.second;
    if(amx==-1 && asmx==-1)
    return b;
    if(bmx==-1 && bsmx==-1)
    return a;
    if(amx>bmx)
    {
        fmx=amx;
        
        if(asmx!=-1)
        {
            fsmx=max(bmx,asmx);
        }
        else 
        {
            fsmx=bmx;
        }
    }
    else 
    {
        fmx=bmx;
        if(bsmx!=-1)
        {
            fsmx=max(bsmx,amx);
        }
        else 
        {
            fsmx=amx;
        }
    }
    return {fmx,fsmx};
}
pair<int,int> answerquery(int id,int l,int r,int ll,int rr)
{
    if(l>rr || r<ll)
    return {-1,-1};

    if(l>=ll && r<=rr)
    {
        return {t[id].mx,t[id].smx};
    }
    int mid=l+((r-l)>>1);
    return findanswer(answerquery(id<<1,l,mid,ll,rr),answerquery(id<<1|1,mid+1,r,ll,rr));

}
void solve()
{
   
    cin>>n;
    arr.resize(n+2);
    for(int i=1;i<=n;i++)
    cin>>arr[i];
    int q;
    cin>>q;
    build(1,1,n);
    while(q--)
    {
        char ch;
        cin>>ch;
        int a,b;
        cin>>a>>b;
        if(ch=='U')
        {
            update(1,1,n,b,a);
        }
        else if(ch=='Q')
        {
            pair<int,int>ans=answerquery(1,1,n,a,b);
            int anss=ans.first+ans.second;
            cout<<anss<<endl;
        }
    }
}
signed main()
{
  cin.tie(0); cout.tie(0);
  solve();
}