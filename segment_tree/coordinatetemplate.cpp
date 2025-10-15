#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
vector<int> arr;
map<int,int> cord;
vector<int> rev;
int t[400000];

void build(int id,int l,int r)
{
    if(l==r)
    {
        t[id]=0; return ;
    }
    int mid=l+((r-l)>>2);
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    t[id]=t[id<<1]+t[id<<1|1];
    return ;
}
void update(int id,int l,int r,int val)
{
    if(cord[val]<l || cord[val]>r)
    return ;

    if(l==r)
    {
        t[id]=1;
        return ;
    }
    int mid=l+((r-l)>>1);
    update(id<<1,l,mid,val);
    update(id<<1|1,mid+1,r,val);
    t[id]=t[id<<1]+t[id<<1|1];
    return ;
}
int answerquery(int id,int l ,int r, int val)
{
    if(cord[val]<l)
    return 0;

    if(cord[val]>=r)
    return t[id];

    int mid=l+((r-l)>>1);
    return answerquery(id<<1,l,mid,val) + answerquery(id<<1|1,mid+1,r,val);
}
void solve()
{
    int n;
    cin>>n;
    arr.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    for(int i=0;i<n;i++)
    {
        cord[arr[i]];
    }
    int cnt=0;
    for(auto &x:cord)
    {
        x.second=cnt++;
        rev.push_back(x.first);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int a;
        cin>>a;
        if(a==1)
        {
            int b;
            cin>>b;
            int val=arr[b];
            update(1,0,n-1,val);
        }
        else 
        {
            int b;
            cin>>b;
            int val=arr[b];
            cout<<answerquery(1,0,n-1,val)<<endl;
        }
    }
    

}
signed main()
{
  cin.tie(0); cout.tie(0);
  solve();
}