#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
signed main(){
    lli t;
    cin>>t;
    
    while(t--){
        lli n;
        cin>>n;
        bitset<64> num(n);
        
        // 1 
        if(n>=0){
            cout<<num<<endl;
        }
        else{
            lli x=-n;
            x=x-1LL;
            x=~x;
            num=x;
            cout<<num<<endl;
        }

        //2
        if(n==0)
        cout<<-1<<endl;
        else
        {
        for(lli i=63;i>=0;i--)
        {
            if(num[i])
            {
                cout<<i<<endl;
                break;
            }
        } 
        }

        //3
        if(n==0)
        cout<<-1<<endl;
        else
        {
        for(lli i=0;i<=63;i++)
        {
            if(num[i])
            {
                cout<<i<<endl;
                break;
            }
        } 
        }

        //4
        lli x=n;
        lli sgn=0;
        if(x<0){
            x=-x;
            sgn=1;// negative sign
        }
        
        // when n==0 or 1 
        if(x==0 || x==1 || sgn==1)
        {
            cout<<0<<endl;
        }

        else
        {
            bool flag=false;
            lli ans=0;
            for(lli i=1;i<=63;i++)
            {
                if((1LL<<i)==x)
                {
                    // we can also add the case when sgn is 1 and the power is even, then also it won't give solution
                    ans=1;
                    break;
                }

            }
            cout<<ans<<endl;
        }

        //5
       
        if(x==0)
        {
            cout<<-1<<endl;
        }
        else
        {
            bool flag=false;
            lli ans=-1;
            for(lli i=0;i<=63;i++){


                if((x % (1LL<<i))==0)
                {
                    ans=max(ans,i);
                    flag=true;
                }
            }
            if(flag){
                cout<<(1LL<<ans)<<endl;
            }
            else{cout<<-1<<endl;}
        }

        //6
        for(lli i=1;i<=63;i++)// as 10^18 can be represented using 60 bits , so there is a no which is greater than n , represented using all the 64 bits;
        {
            if((1LL<<i)>=n)
            {
                cout<<(1LL<<i)<<endl;
                break;
            }
        }

        
       
    
    }
    
   
}