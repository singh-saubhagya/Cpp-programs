#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
size_t npos = string::npos;
struct solvequery{
    lli q;
    vector<lli> arr;
    string trim(string str)
    {
        string temp;
        lli l=str.length();
        lli st=0,en=l-1;
        for(lli i=0;i<l;i++)
        {
            if(str[i] !=' ')
            {
                st=i;
                break;
            }
        }
        for(lli i=l-1;i>=0;i--)
        {
            if(str[i] !=' ')
            {
                en=i;
                break;
            }
        }
        if(str[st]==' '&& str[en]==' ')
        {
            return NULL;
        }
        else
        {
        temp=str.substr(st,en-st+1);
        return temp;
        }

    }
    void initialize()
    {
    cin>>q;
    string str;
    cin.ignore();
        for(lli i=0;i<q;i++)
        {
            getline(cin,str);
            // assuming the string is trim;
            str=trim(str);
            lli l=str.length();
            lli in,en;
            if(str.find("add")!=npos)
            {
               in=str.find("add")+4;// index of the no
               en=l-in+1;
               lli x=stoi(str.substr(in,en));
               arr.push_back(x);
               
            }
            else if(str.find("remove")!=npos)
            {
                if(arr.size()>0)
                arr.resize(arr.size()-1);
                
            }
            else if (str.find("print")!=npos)
            {
                
                in=str.find("print")+6;
                en=l-in+1;
                lli x=stoi(str.substr(in,en)); 
                if(arr.size()>0 && x<=arr.size()-1)
                {
                    cout<<arr[x]<<endl;
                }
                else
                cout<<"0"<<endl;
            }
            else if (str.find("clear")!=npos)
            {
                arr.clear();
            }

        }
    }

};
signed main()
{
  lli t;
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cin>>t;
  while(t--)
  {
     solvequery x;
     x.initialize();
     
  }
}