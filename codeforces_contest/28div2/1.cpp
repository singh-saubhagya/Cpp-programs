#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
void solve()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    
    if(a>b)
    {
        swap(a,b);
        swap(c,d);
    }
   
        int gap=a+1;
        if(gap*2<b)
        {
            cout<<"NO"<<endl;
            return;  
        }
        else 
        {
            
                int cc,dd;
                int i=1;
                while(true)
                 {
                    cc=c*i;
                    dd=d*i;
                    if(cc>=a && dd>=b)
                    break;
                    i++;
                 }
                 int gc=cc-a;
                 int gd=dd-b;
                 if(gc>gd)
                 {
                    swap(gc,gd);
                 }
                 int gap2=gc+1;
                 if(gap2*2<gd)
                 {
                    cout<<"NO"<<endl;
                    return ;
                 }
                 cout<<"YES"<<endl;
            
        }
    

}
signed main()
{
  cin.tie(0); cout.tie(0);
  int t;
  cin>>t;
  while(t--)
  solve();
}