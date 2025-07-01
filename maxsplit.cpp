#include<bits/stdc++.h>
using namespace std;
typedef long long lli;

int main()
{
    vector<string> arr;
    string temp;
    string str;
    cin>>str;
    lli ans=0;
    int n=str.length();
    lli ct=0;
    for(lli i=0;i<n;i++)
    {
        char ch=str[i];
        
        if(ch=='L')
        {
            ct++;
            
            temp.push_back(ch);continue;
        }
        else if(ct>0)
        {
            for(;i<n;i++)
            {
            char bh=str[i];
           
            if(bh=='R')
            {
                ct--;
                temp.push_back(bh);
                if(ct==0)
                {
                ans+=1;

                arr.push_back(temp);
                temp.resize(0);
                
                break;

                }
            }  
            else
            { 
                temp.resize(0);
                i=n;
                ct=0;
                break;
               
            }
            }
        }
        
    }
    if(ans==0)
    {
        cout<<1<<endl;
        cout<<str<<endl;
    }
    else
    {cout<<ans<<endl;
      for(auto x:arr)
      {
        cout<<x<<endl;
      }
    }
    return 0;
}