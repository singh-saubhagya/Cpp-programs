#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
 vector<lli> arr;
 lli n, k;
bool check(lli mid) {
    
    lli count=1;
    lli st=0;
    for(lli en=1;en<n; en++ )
    {
        if(arr[en]-arr[st]>=mid)
        {
            count++;
            st=en;  
            if(count==k)
            {
                return true;
            }
        }
       
    }
    if(count>=k)
    return true;
    else
    return false;

}

void solve() {
    
    cin >> n >> k;
    arr.resize(n);

    for (lli i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());

    lli lo = 1;
    lli hi = arr[n - 1] - arr[0];
    lli ans = 0;
    
    while (lo <= hi) 
    {
        
        lli mid = lo + (hi - lo) / 2;
        if (check( mid)) {

            ans = mid; // Found a valid distance
            lo = mid + 1; // Try for a larger distance
        } else {
            hi = mid - 1; // Try for a smaller distance
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    lli q;
    cin >> q;
    while (q--)
    {
        solve();
    }
    
}