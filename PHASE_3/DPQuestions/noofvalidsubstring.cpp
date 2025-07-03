// count all the valid substring of parenthesis

#include<bits/stdc++.h>
using namespace std;
signed main(){
   
    string str;
    cin>>str;
    map<int,int> a,b;
    stack<int> s;
    for(int i=0;i<str.length();i++){
        if(str[i]=='('){
            s.push(i);
        }
        else 
        {
            if(s.empty()==false){
                a.insert({i,s.top()});
                s.pop();
            }
            else 
            {
                a.insert({i,-1});    
            }
        }
    }
    

    for(int i=0;i<str.length();i++){
        int x=-1;
        if(str[i]==')'){
            if(a[i]>=0)// their exist an opening bracket correspoding to it
            {
                x=a[i];// index of opening bracket
                b[i]++;// increasing the ending by 1
            }
        }
        x--;
        // now if this x is closing 
        if(x>=0 && str[x]==')'){
            if(a[x]>=0)// 
            {
                b[i]+=b[x];
            }
        }
        
    }
    int ans=0;
    for(auto x:b){
        ans+=x.second;
       }
       cout<<ans<<endl;
}