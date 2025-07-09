#include<bits/stdc++.h>
using namespace std;
 
 int findcommon(string a,string b)
    {
        if(a.length() ==0 || b.length()==0)
        return 0;
        int x=min(a.length(),b.length());
        int ct=0;
        if(a==b)
        return x;
        
        for(int i=0;i<x;i++)
            {
                if(a[i]==b[i])
                {
                    ct++;
                }
                else break;
            }
        return ct;
    }
    vector<int> longestCommonPrefix(vector<string>& words) {
        vector<vector<int>> match;
        int l=words.size();
        vector<int> mb;
        vector<int> ma;
        mb.resize(l+2);
        ma.resize(l+2);
        int ans=0;
        mb[0]=0;
        ma[l-1]=0;
        for(int i=1;i<l;i++)
            {
                int en=i-1;
                ans=max(findcommon(words[i],words[en]),ans);
                mb[i]=ans;
            }
        ans=0;
        for(int i=l-2;i>=0;i--)
        {
            int st=i+1;
             ans=max(findcommon(words[i],words[st]),ans);
            ma[i]=ans;
        }
        vector<int> sol;
        for(int i=0;i<l;i++)
            {
                int a=i-1;
                int b=i+1;
                int ans1=0;
                int ans2=0;
                if(a<0)
                {
                    ans1=0;
                    
                }
                else
                {
                    ans1=mb[a];
                }
                if(b>l-1)
                {
                    ans2=0;
                }
                else 
                {
                    ans2=ma[b];
                }
                int val=max(ans1,ans2);
                if(a>=0 && b<l)
                {
                    val=max(val,findcommon(words[a],words[b]));
                }
                sol.push_back(val);
            }
        return sol;
    }


    signed main()
    {
        vector<string> words;
        words={"jump","run","run","jump","run"};
        vector<int> arr=longestCommonPrefix(words) ;
        for(auto x:arr)
        cout<<x<<" ";
    }