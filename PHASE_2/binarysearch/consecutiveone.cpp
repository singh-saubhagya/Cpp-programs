#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
#define int long long
vector<lli> arr;
vector<lli> presum;
vector<lli> result;
void solve()
 {
    int n,k;
    cin>>n>>k;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
        sum+=x;
        presum.push_back(i+1-sum);//storing no of zeros 
    }
    auto it=presum.begin();
    int count=0;
   for(int st=0;st<arr.size();st++)
   {
        
        int end=upper_bound(it,presum.end(),k)-it;
        it++;
        int length=end-st;
        count+=length;
   }
   result.push_back(count);
    
 }
 signed main()
 {
   int q;
   ios_base::sync_with_stdio(0);
   cin.tie(0);cout.tie(0);
   cin>>q;
   cout<<endl;

   while(q--)
   {
    solve();
    arr.clear();
    presum.clear();
   }
   for(int i:result)
   {
        cout<<i<<endl;
   }

 }