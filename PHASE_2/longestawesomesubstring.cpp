#include<bits/stdc++.h>
using namespace std;

// bitmasking helps us to store any specific property at distinct pn !!!!


signed main(){
    string str;
    cin>>str;

    map<int,int> m;
    int l=str.length();
    int temp=0;

    int ans=0;
    
    for(int i=0;i<l;i++){
        int val=str[i]-'0';
        temp=temp^(1<<val);
      
        if(temp==0)// case 1 , when 
        {
            ans=i+1;
        }
        else 
        {
            int ct=0;
            for(int j=0;j<10;j++){
                if((temp>>j)&1)
                {
                    ct++;
                }
            }
            if(ct==1)
            {
                ans=i+1;
               
            }
            else
            {
                for(int k=0;k<10;k++)
                {
                    int y=temp;
                    y=y^(1<<k);
                    
                    if(m.find(y)!=m.end()){
                        ans=max(ans,i+1-m[y]);
                    }
                }
            }
        }
        if(m.find(temp)==m.end()){
            m[temp]=i+1;
           
        }
    }
    
    cout<<ans<<endl;
}