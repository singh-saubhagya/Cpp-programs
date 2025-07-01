#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
lli n,k;
set<string> allsol; string sol;
lli ct=0;
void rec(int i, int depth)
{
    if(depth>k|| depth <0 )
    return ;
    if(i==n)
    {
        if(depth==0)
        {
            allsol.insert(sol);
            ct++;
            return;
        }
        else return ;
    }
    
    sol.push_back('(');// saves time complexity by n
    rec(i+1,depth+1);
    sol.pop_back();// backtracking 

    sol.push_back(')');
    rec(i+1,depth-1);
    sol.pop_back();
     
    
}
int main(){
    cin>>n>>k;
    rec(0,0);
    cout<<ct<<endl;
    for(auto v:allsol){
        cout<<v<<endl;
    }
}