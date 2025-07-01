
#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'


struct mystack{
stack<lli> s1,s2;


void push(lli x)
{
  s1.push(x);
}

void pop()
{
if(s2.empty())
  {
    while(!s1.empty())
      {
          s2.push(s1.top());
          s1.pop();
      }
  }
cout<<s2.top()<<endl;
s2.pop();
}



 
void ans_to_stackquery()
    {
          lli q;
          cin>>q;
            while(q--)
            {             
              string str;
              cin>>str;
              if(str=="push")
                {
                  lli no;
                  cin>>no;
                  push(no);
                  
                }
              else if(str=="pop")
                {
                  pop(); 
                }
              else if(str=="front")
                {
                  if(s2.empty())
                  {
                    while(!s1.empty())
                    {
                        s2.push(s1.top());
                        s1.pop();
                    }
                  }
                   cout<<s2.top()<<endl;
                }
            }
          

      
    }
};


signed main()
{

 
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  lli t;
  cin>>t;

  while(t--)
  {
    mystack s;
    s.ans_to_stackquery();
    
  }
  
}