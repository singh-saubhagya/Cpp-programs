#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'


void solve()
{
    int q;int k;
    cin>>q>>k;
    multiset<int> s;
    lli sum=0;
    auto kth=s.begin();
    while(q--)
    {
        int a,x;
        cin>>a;
        if(a==1)
        {
            cin>>x;
            if(s.size()<k)
            {
                sum+=x;
                s.insert(-x);
                kth=s.end();
                kth--;
            }
            else 
            {
                int val=*kth;
                val=val*-1;
                if(x>val)
                {
                    sum-=val;
                    sum+=x;
                    s.insert(-x);
                    if(kth!=s.begin());
                    kth--;
                }
                else 
                {
                    s.insert(-x);
                }
            }
        }
        else if(a==2)
        {
            cin>>x;
            if(s.find(-x)!=s.end())
            {
                auto it=s.find(-x);
                if(s.size()<=k)
                {
                    sum-=x;
                    s.erase(it);
                    if(s.size()>=1)
                    {
                     kth=s.end();
                     kth--;
                    }
                    
                }
                 else 
                {
                    int val=*kth;
                    if(x>val)
                    {
                        kth++;
                        if(kth!=s.end())
                        sum+=(-*kth);
                        sum-=x;
                        s.erase(it);
                    }
                    else 
                    {
                        s.erase(it);
                    }
                }
            }
           
           
        }
        else if (a==3)
        {
            char ch;
            cin>>ch;
            cout<<sum<<endl;
        }
        

    }
}
signed main()
{
    solve();
}