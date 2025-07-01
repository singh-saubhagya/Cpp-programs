#include<bits/stdc++.h>
using namespace std;

void rec(int n, int balnc, int level, string &str)
{
    if(level==n)
    {
        if(balnc==0)
        {
            cout<<str<<endl;
            return;
        }
        return;
    }
    if(balnc<0 || balnc>(n/2))
    return;


    str.push_back('(');
    balnc++;
    level++;
    rec(n,balnc,level,str);

    str.pop_back();// backtracking , used to choose other options
    balnc--;
    level--;
    
    str.push_back(')');
    balnc--;
    level++;
    rec(n,balnc,level,str);

    str.pop_back();// backtracking , used to choose other options
    balnc--;
    level--;
    
    
}
signed main()
{
     int n;
     cin>>n;
     string str="";
     rec(n,0,0,str);
}