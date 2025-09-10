
#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
 const int inf=1e9;
    int minOperations(string s, int k) {
        int n=s.length();
        int a=0,b=0;
        for(int i=0;i<n;i++)
            {
                int x=s[i]-'0';
                if(x)
                a++;
                else 
                b++;
            }
        int ans=b/k;
        b=b%k;
        if(b==0)
            return ans;
        a=n-b;
        int left=k-b;
    
        while(left)
            {
                bool flag=false;
                for(int i=left;i>=1;i--)
                    {
                        int need1=i;
                        int sl=k-need1;
                        if(sl&1)
                        continue;
                        int lef1=a-need1;
                        int m1=sl/2;
                        int m0=sl/2;
                      
                        if(m1<=lef1 && m0<=b)
                        {
                          
                            // state chagne 
                            left=left-i;
                            int new1=a-need1;
                            int new0=b+i;
                            ans++;
                            a=new1;
                            b=new0;
                            flag=true;
                            break;
                        }
                       
                    }
                 if(flag==false )
                       {cout<<left<<endl;     
                        return -1 ;}
            }
        return ans+1;
    }
signed main()
{
  cin.tie(0); cout.tie(0);
  string str="0000";
  int k=3;
  cout<<minOperations(str,k)<<endl;
}