#include<bits/stdc++.h>
using namespace std;
#define tab '\t'
// solve 2 is the most optimal solution than solve so use maps!!!
vector<string> result;
string solve(int a,int b)
{
    vector<int> v;
    // int a,b;
    // cin>>a>>b;
    string str;
    if((a<0)^ (b<0)){
        str.push_back('-');
    }
    a=abs(a);
    b=abs(b);
    if (a%b==0)
    {
        str+=(to_string(a/b));
    }
    else
    {
        str+=(to_string(a/b));
        // cout<<to_string(a/b)<<endl;
        // cout<<str<<endl;
        str.push_back('.');
        int lnt=str.length();
        int rem=a%b;
        v.push_back(rem);
        int pn=lnt;
        int repeat=0;
        while(1)
        {
            int quo;
            rem=rem*10;
            quo=rem/b;
            rem=rem%b;
            str.push_back('0' +quo);
            // cout<<str<<endl<<"hello";
            // cout<<quo<<"hello";
            if(rem==0)
            {
                break;
            }
            else if(find(v.begin(),v.end(),rem)!=v.end())
            {
                repeat=1;
               pn+=find(v.begin(),v.end(),rem)-v.begin();
               
               break;
            }
            else
            {
              v.push_back(rem);  
            }
            
        }
        if(repeat==1)
        {
            str.insert(pn,1,'(');
            str.push_back(')');
        }
    }
    return str;

}

string solve2(int a,int b)
{
     string str;
    if ((a < 0) ^ (b < 0)) {
        str.push_back('-');
    }
    a = abs(a);
    b = abs(b);
    if (a == 0) {
        return "0";
    }
    if (a < b) {
        str += "0.";
    } else {
        str += (to_string(a / b));
        a %= b;
        if (a == 0) {
            return str;
        }
        str += ".";
    }
    unordered_map<int, int> v;
    while (a != 0) {
        if (v.find(a) != v.end()) {
            int pos = v[a];
            string temp = str.substr(pos);
            str.erase(pos, str.length() - pos);
            str += "(" + temp + ")";
            break;
        }
        v[a] = str.length();
        a *= 10;
        str += (char)(a / b + '0');
        a %= b;
    }
    return str;
}
int main()
{
    int q=100000;
    //  cin>>q;
    while(1)
    {
    //  int  a, b;
     
      int  a=rand()%101;
      int  b=rand()%100+1;
    //  cin>>a>>b;
    string str=  solve(a,b);
    string str1= solve2(a,b);
    if(str!=str1)
{cout<<str<<tab<<str1<<tab<<a<<tab<<b<<endl;break;}
    // result.push_back(str);
    }
    // cout<<endl;
    // for(string s:result)
    // {
    //     cout<<s<<endl;
    // }
}