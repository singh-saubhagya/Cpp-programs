#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
// how are we checking is the sequence of parenthesis balance or not , 
// we are using depth variable , starting with 0 , as soon as we get ( , we incease the depth by 1 and as we get ) we decrease the depth, and if at any pn we find out depth < 0 , then it is a invalid string
// and for depth==0 it means it is balanced, also we are thinking in a way like assigning each parenthesis a depth, like ((())), the depth of this is 123210, at each insertin of ( or ) we check whether we obtain any max depth or not 

void rec(int n,int k,int depth,int level,string &str,int md)
{
     if(depth<0 || md>k)
     return;
     if(level==n)
     {
        if(depth==0 && md==k)
        {
            cout<<str<<endl;
            return;
        }
        return;
     }
     str.push_back('(');
     depth++;
     level++;
    
     rec(n,k,depth,level,str,max(md,depth)); // we are passing max()fn and not using int md=max(md,depth) because it will change the local varible state , i.e if the value of depth is greater , then md will change, there fore while pushing the ) after backtraking md will assigned with the new depth which we don't want as we want to preserve the local state .

     str.pop_back();// backtraking 
     depth--;
     level--;

     str.push_back(')');
     depth--;
     level++;

     rec(n,k,depth,level,str,max(md,depth));

     str.pop_back();// backtracking
     depth++;
     level--;
     
     
}
signed main()
{
    int n,k;
    cin>>n>>k;
    string str="";
    //0 max depth see till now 
    rec(n,k,0,0,str,0);//n,k,depth,level,str
}