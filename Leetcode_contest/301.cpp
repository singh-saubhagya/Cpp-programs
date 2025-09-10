#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'

    int score(vector<string>& cards, char x) {
        vector<int> a,b;
        a.assign(15,0);
        b.assign(15,0);
        int ct=0;
        int n=cards.size();
        for(int i=0;i<n;i++)
            {
                string str=cards[i];
                if(str[0]==x && str[1]!=x)
                {
                    int pn=str[1]-'a';
                    a[pn]+=1;
                }
                if(str[1]==x && str[0]!=x)
                {
                    int pn=str[0]-'a';
                    b[pn]+=1;
                }
                if(str[0]==x && str[1]==x)
                {
                 ct++;   
                }
            }
            cout<<ct<<" "<<endl;
            for(int i=0;i<10;i++)
            {
                cout<<a[i]<<" ";
            }
            cout<<endl;
            for(int i=0;i<10;i++)
            {
                cout<<b[i]<<" ";
            }
            cout<<endl;
        priority_queue<int> pq1,pq2;
        for(int i=0;i<10;i++)
            {
                
                if(a[i]>0)
                pq1.push(a[i]);
                if(b[i]>0)
                pq2.push(b[i]);
            }
        int ans=0;
        int rem1=0;
        while(pq1.empty()==false)
            {
                int val1=pq1.top();
                pq1.pop();
                if(pq1.empty()==true)
                {
                    rem1=val1;
                    break;
                }
                int val2=pq1.top();
                pq1.pop();
                ans+=min(val1,val2);
                int diff=val1-val2;
                if(diff>0)
                {
                    pq1.push(diff);
                }
            }
        int rem2=0;
        while(pq2.empty()==false)
            {
                int val1=pq2.top();
                pq2.pop();
                if(pq2.empty()==true)
                {
                    rem2=val1;
                    break;
                }
                int val2=pq2.top();
                pq2.pop();
                ans+=min(val1,val2);
                int diff=val1-val2;
                if(diff>0)
                {
                    pq2.push(diff);
                }
            }
            
        int rem=rem1+rem2;
        
        ans+=min(ct,rem);
        return ans;
        
    }

signed main()
{
  cin.tie(0); cout.tie(0);
  vector<string> a={"ab","aa","ab","bc","cc","bc","bb","ac","bc","bc","aa","aa","ba","bc","cb","ba","ac","bb","cb","ac","cb","cb","ba","bc","ca","ba","bb","cc","cc","ca","ab","bb","bc","ba","ac","bc","ac","ac","bc","bb","bc","ac","bc","aa","ba","cc","ac","bb","ba","bb"};
  char ch='b';
  cout<<score(a,ch);
}