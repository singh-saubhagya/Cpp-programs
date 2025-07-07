#include<bits/stdc++.h>
using namespace std;

 string concatHex36(int  n) {
        string a,b;
        int  n1=n*n;
        int n2=n*n*n;
            while(n1!=0)
            {
               int x=n1%16;
                char ch;
                if(x<=9)
                {
                    ch='0'+x;
                }
                else 
                {
                    ch='A'+x-10;
                }
                a.push_back(ch);
                n1=n1/16;
            }
            reverse(a.begin(),a.end());
            
        while(n2!=0)
            {
                int  x=n2%36;
                char ch;
                if(x<=9)
                {
                    ch='0'+x;
                }
                else 
                {
                    ch='A'+x-10;
                }
                b.push_back(ch);
                 n2=n2/36;
            }
       
        reverse(b.begin(),b.end());
        return a+b;
    }

    signed main(){
        int n;
        cin>>n;
        cout<<concatHex36(n);
    }