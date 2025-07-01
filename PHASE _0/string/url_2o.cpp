#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'

signed main()
{
 string arr[5];
 string str;
 getline(cin,str);
 int l=str.length();
 
 int st,en;
 st=str.find("username") +9;
 en=str.find("&",st);
 arr[0]=str.substr(st,en-st);
 st=str.find("pwd") +4;
 en=str.find("&",st);
 arr[1]=str.substr(st,en-st);
 st=str.find("profile") +8;
 en=str.find("&",st);
 arr[2]=str.substr(st,en-st);
 st=str.find("role") +5;
 en=str.find("&",st);
 arr[3]=str.substr(st,en-st);
 st=str.find("key") +4;
 arr[4]=str.substr(st);

cout<<"username: "<<arr[0]<<endl;
cout<<"pwd: "<<arr[1]<<endl;
cout<<"profile: "<<arr[2]<<endl;
cout<<"role: "<<arr[3]<<endl;
cout<<"key: "<<arr[4]<<endl;


}