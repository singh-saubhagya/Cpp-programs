#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
int n,q;
lli arr[200005]; // Fixed: increased array size and changed to long long
struct node{
    lli advl;  // Fixed: changed to long long
    lli sevl;  // Fixed: changed to long long
    bool isset;
    lli sum=0; // Fixed: changed to long long
    node()
    {
        advl=0;
        sevl=0;
        isset=false;
    }
};
node t[800020]; // Fixed: increased tree size

node combine(int id1,int id2)
{
    node temp;
    temp.sum=t[id1].sum+t[id2].sum;
    return temp;
}

void build(int id,int l,int r)
{
    if(l==r)
    {
        node temp;
        temp.advl=0;
        temp.sevl=0; // Fixed: changed from -1 to 0
        temp.isset=false;
        temp.sum=arr[l];
        t[id]=temp;
        return ; 
    }
    int mid=l+(r-l)/2;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    t[id]=combine(id<<1,id<<1|1);
    return ;
}

void pushlazy(int id,int l,int r)
{
    // Fixed: Handle set operation first, then add operation
    if(t[id].isset)
    {
        t[id].sum = t[id].sevl * (r-l+1);
        if(l != r) // Only propagate if not leaf
        {
            t[id<<1].isset = true;
            t[id<<1|1].isset = true;
            t[id<<1].sevl = t[id].sevl;
            t[id<<1|1].sevl = t[id].sevl;
            t[id<<1].advl = 0; // Clear any pending add operations
            t[id<<1|1].advl = 0;
        }
        t[id].isset = false;
        t[id].sevl = 0;
    }
    
    // Fixed: Check advl != 0 instead of advl > 0 (can be negative)
    if(t[id].advl != 0)
    {
        t[id].sum += (r-l+1) * t[id].advl;
        if(l != r) // Only propagate if not leaf
        {
            if(t[id<<1].isset)
                t[id<<1].sevl += t[id].advl;
            else
                t[id<<1].advl += t[id].advl;
                
            if(t[id<<1|1].isset)
                t[id<<1|1].sevl += t[id].advl;
            else
                t[id<<1|1].advl += t[id].advl;
        }
        t[id].advl = 0;
    }
}

void performset(int id,int l,int r,int ll,int rr,lli val) // Fixed: parameter type
{
    pushlazy(id,l,r);
    if(l>rr || r<ll)
        return ;

    if(l>=ll && r<=rr)
    {
        t[id].advl=0;
        t[id].isset=true;
        t[id].sevl=val;
        pushlazy(id,l,r);
        return ;
    }
    int mid=l+(r-l)/2;
    performset(id<<1,l,mid,ll,rr,val);
    performset(id<<1|1,mid+1,r,ll,rr,val);
    pushlazy(id<<1,l,mid);
    pushlazy(id<<1|1,mid+1,r);
    t[id].sum=t[id<<1].sum+t[id<<1|1].sum;
}

void performadd(int id,int l,int r,int ll,int rr,lli val) // Fixed: parameter type
{
    pushlazy(id,l,r);
    if(l>rr || r<ll)
        return ;
    if(l>=ll && r<=rr)
    {
        if(t[id].isset)
        {
            t[id].sevl += val; // Fixed: simplified logic
        }
        else 
        {
            t[id].advl += val;
        }
        pushlazy(id,l,r);
        return ;
    }
    int mid=l+(r-l)/2;
    performadd(id<<1,l,mid,ll,rr,val);
    performadd(id<<1|1,mid+1,r,ll,rr,val);
    pushlazy(id<<1,l,mid);
    pushlazy(id<<1|1,mid+1,r);
    t[id].sum=t[id<<1].sum+t[id<<1|1].sum;
    return ;
}

lli answerquery(int id,int l,int r,int ll,int rr) // Fixed: return type
{
    pushlazy(id,l,r);
    if(l>rr || r<ll)
        return 0;
    if(l>=ll && r<=rr)
    {
        return t[id].sum;
    }
    int mid=l+(r-l)/2;
    return answerquery(id<<1,l,mid,ll,rr)+answerquery(id<<1|1,mid+1,r,ll,rr);
}

void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    build(1,1,n);
    while(q--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int a,b;
            lli x; // Fixed: changed to long long
            cin>>a>>b>>x;
            performadd(1,1,n,a,b,x);
        }
        else if(type==2)
        {
            int a,b;
            lli x; // Fixed: changed to long long
            cin>>a>>b>>x;
            performset(1,1,n,a,b,x);
        }
        else if(type==3)
        {
            int a,b;
            cin>>a>>b;
            cout<<answerquery(1,1,n,a,b)<<endl;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false); // Fixed: added for better performance
    cin.tie(0); 
    cout.tie(0);
    solve();
    return 0;
}