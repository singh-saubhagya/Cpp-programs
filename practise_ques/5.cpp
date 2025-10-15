#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
void solve()
{
  lli n,k;
  cin>>n>>k;
  string str;
  cin>>str;
  deque<lli> dq;
  for(int i=1;i<=n;i++)
  {
    dq.push_back(i);
  }
  lli a=-2;
  lli b=0;
  vector<int> status;
  status.assign(n+2,0);
  bool bomb=false; 
  for(int i=0;i<k;i++)
  {
    if(dq.empty()==true)
    {
        bomb=true;
        break;
    }
    int at=str[i]-'0';
    
    if(at==0)
    {
        int ele=dq.front();
        if(status[ele]==3)
        {
          if(status[a+1]==0)
          {
            status[a+1]=3;
            a++;
          }
        }
        status[ele]=1;// outside 
        dq.pop_front();
    }
    else if (at==1)
    {
      int ele=dq.back();
      if(status[ele]==3)
      {
        if(status[b-1]==0)
        {
          status[b-1]=3;
          b--;
        }

      }
      status[ele]=1;
      dq.pop_back();
    }
    else 
    {
     
      if(a==-2 && b==0 )
      {
        int ele=dq.front();
          status[ele]=3;
           a=ele;
        
          ele=dq.back();
          status[ele]=3;
          b=ele;
        
      }
      else 
      {
        if(b-a==1 || b-a==0)
        {
          bomb=true;
          break;
        }
        if(a+1<=n )
        {
          if(status[a+1]==0)
          {
            status[a+1]=3;
            a++;
          }
         
        }
        
         if(b-1>=1)
         {
          if(status[b-1]==0)
          {
            status[b-1]=3;
            b--;
          }
        }
      }

    }
    //  cout<<"action"<<" "<<at<<endl;
    //  for(int j=1;j<=n;j++)
    //   {
    //     cout<<j<<" "<<status[j]<<endl;
    //   }
    if(a>=b)
    {
      bomb=true;
      
      break;
    }

  }
  if(bomb)
  {
    for(int i=1;i<=n;i++)
    {
      cout<<"-";
    }
    cout<<endl;
    return; 
  }
  for(int i=1;i<=n;i++)
  {
    if(status[i]==0)
    {
      cout<<"+";
    }
    else if (status[i]==1)
    {
      cout<<"-";
    }
    else 
    cout<<"?";
  }
  cout<<endl;
  return;
}

signed main()
{
  cin.tie(0); cout.tie(0);
  int t;cin>>t;while(t--)solve();
}