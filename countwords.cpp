#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  string str;
  getline(cin,str);
  lli ct=0;
  string temp="";
  for(lli i=0;i<str.length();i++){
    char ch=str[i];
    if( ((ch >=65 && ch<=90) || (ch>=97 && ch<= 122)) ) {
        temp+=ch;
    }
    else if(ch=='.' || ch=='?' || ch ==' ' || ch== ',' || ch=='!' )
    {
        if(temp!="")
        ct++;
        temp="";
    }
    if( i==str.length()-1 &&  ((ch >=65 && ch<=90) || (ch>=97 && ch<= 122))  )
    {
        ct++;
    }
     
  }
  cout<<ct<<endl;
}