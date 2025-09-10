#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
lli  findanswer(lli  n )
{
    n++;
    lli  bsize=10;
    lli  ans=0;
    lli  nn=n;
    lli  ct=0;
    while(nn!=0)
    {
        ct++;
        nn=nn/10;
    }

    for(lli  i=1;i<=ct;i++)
    {
        lli  val1=n/bsize;
        
        lli  rep=bsize/10;
        for(lli  j=1;j<=9;j++)
        {
            ans+=j*rep*val1;
           
        }
        lli  val2=n%bsize;
        lli  val=0;
        lli  val3=val2/rep; 
        lli  rem2=0;
        lli  j=0;
        for(;j<val3;j++)
        {
            ans+=j*rep;
        }
        lli  val4=val2%rep;
        ans+=j*val4;
        bsize*=10;
    }
    return ans;
}
void solve()
{
    lli  k;
    cin>>k;
    if(k<=9)
    {
        cout<< k*(k+1)/2<<endl;
        return ;
    }
    k++;
    
    vector<lli > a,b;
    b.resize(20);
    a.resize(20);
    lli  val=90;
    a[0]=b[0]=0;
    a[1]=10;
    b[1]=10;
    for(lli  i=2;i<=15;i++)
    {

        a[i]=val*i;
        val*=10;
        b[i]=a[i]+b[i-1];
        
    }
   
    lli  num=lower_bound(b.begin(),b.end(),k)-b.begin();
    lli  val1=1;
    for(lli  i=1;i<=num-1;i++)
    {
        val1=val1*10;
    }
    lli  ans=0;
    lli  val2=k-b[num-1];
    lli  val3=val2/num;
    lli  val4=val1+(val3-1);
   
    ans=findanswer(val4);
    lli  num2=val4+1;
    lli  left=val2%num;
    vector<lli > temp;
    while(num2!=0)
    {
        temp.push_back(num2%10);
        num2=num2/10;
    }
    reverse(temp.begin(),temp.end());
    for(lli  i=0;i<left;i++)
    {
        ans+=temp[i];
    }
    cout<<ans<<endl;

}
signed main()
{
  cin.tie(0); cout.tie(0);
  lli  t;
  cin>>t;
  while(t--)
  solve();
}