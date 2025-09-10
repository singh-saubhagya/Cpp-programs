   
   #include<bits/stdc++.h>
   using namespace std;
   typedef long long lli;
   #define endl '\n'
   #define tab '\t'
   long long minArraySum(vector<int>& A, int k) {
        vector<long long> dp(k, LLONG_MAX);
        dp[0] = 0;
        long long res = 0;
        for (int a : A) {
            res += a;
            res = dp[res % k] = min(dp[res % k], res);
        }
        return res;
    }
   void solve()
   {
    int n;
    cin>>n;vector<int>arr;arr.resize(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int k;
    cin>>k;
    cout<<minArraySum(arr,k)<<endl;
   }
   signed main()
   {
     cin.tie(0); cout.tie(0);
     solve();
   }
   