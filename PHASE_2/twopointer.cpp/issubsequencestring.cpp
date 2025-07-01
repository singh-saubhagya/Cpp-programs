#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
void solve()
{
    string str1,str2;
    cin>>str1>>str2;
    // check whether str2 is the subsequence of str1
    int p1=0,p2=0;
    while(p1<str1.size())
    {
        if(str1[p1]==str2[p2])
        {
            p1++;
            p2++;
        }
        else
        {
            p1++;
        }
        if(p2==str2.size())
        {
            break;
        }
        


    }
    if(p2==str2.size())
    {
        cout<<"True"<<endl;
    }
    else
    cout<<"False"<<endl;
}
signed main()
{
  
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  
  solve();
  

}