#include<bits/stdc++.h>
using namespace std;
#define tab '\t'
#define  endl '\n'
#define lli long long
vector<string> result;
signed main()
{
    string str;
    getline(cin,str);
    lli l=str.length();
    string temp,temp2;
    for(lli i=0;i<l;i++)
    {
        char ch=str[i];
        if(ch>=65 && ch<=90 || ch>=97 && ch<=122)
        {
            temp=temp+ch;

        }
        else 
        {
           if(temp=="username" ||temp== "pwd" || temp=="profile"||temp=="role"  || temp=="key")
           {
                i=i+1;
                
                for(;i<l;i++)
                {
                    char ch2=str[i];
                    if((ch2>=65 && ch2<=90) || (ch2>=97 && ch2<=122) || (ch2>=48 && ch2<=57))
                    {
                    temp2=temp2+ch2;
                    if(i==l-1)
                    {
                        result.push_back(temp2);
                        break;
                    }
                    }
                   else{
                    result.push_back(temp2);
                    break;
                       }
                 }
            }
            temp.resize(0);
            temp2.resize(0);
        }
      
    }
    cout<<"username: "<<result[0]<<endl;
    cout<<"pwd: "<<result[1]<<endl;
    cout<<"profile: "<<result[2]<<endl;
    cout<<"role: "<<result[3]<<endl;
    cout<<"key: "<<result[4]<<endl;


}