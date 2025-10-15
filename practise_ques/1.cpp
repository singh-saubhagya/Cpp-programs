#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

void solve() {
    lli n;
    cin >> n;
    
    vector<lli> l(n), r(n);
    lli l_min = 1e9 + 1, r_max = 0;
    lli sum = 0;
    
    for (lli i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        l_min = min(l_min, l[i]);
        r_max = max(r_max, r[i]);
    }
    
    cout << (r_max - l_min) * (n - 1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    lli t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}
