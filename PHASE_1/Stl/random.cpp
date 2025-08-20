#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
void solve()
{

}


long long minArraySum(vector<int>& nums, int k) {
        lli sum=0;
        stack<lli> s;
        map<lli,lli> m;
        m[0]=1;
        int n=nums.size();
       
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int x=sum%k;
          
            if(m[x]>0)
            {
                while(s.empty()==false && (s.top()%k)!=x)
                {
                    m[s.top()%k]=0;
           
                    s.pop();
                    
                }
                if(!s.empty())
                {
                    m[s.top()%k]=0;
                    s.pop();
                }

                if(s.empty()==false)
                {
                    sum=s.top();
                }
                else 
                sum=0;
           
                m[0]=1;
            }
            else 
            {
                m[x]=1;
                s.push(sum);
            }
        }
      
        return sum;
    }

signed main()
{
  cin.tie(0); cout.tie(0);
  vector<int> arr={3,1,4,1,5};
  int k=3;
  cout<<minArraySum(arr,k);
}