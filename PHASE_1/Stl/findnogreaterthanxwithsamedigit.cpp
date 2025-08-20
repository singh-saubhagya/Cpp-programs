#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'

lli n;
int l = 0;
vector<int> orig;
lli finans = LLONG_MAX;

void rec(vector<int>& res, vector<int>& ct, int pn, int tight) {
    // Base case: filled all positions except last
    if (pn == l - 1) { // Change to l - 1 to fill the last position
        lli ans = 0;
        for (int i = 0; i < l; i++) {
            ans = ans * 10 + res[i];
        }
        
        if (ans > n) {
            finans = min(ans, finans);
        }
        return;
    }
    
    int di = orig[pn];
    
    if (tight == 1) {
        // Case 1: Try to place the same digit (maintaining tight constraint)
        if (ct[di] > 0) {
            res[pn] = di;
            ct[di]--;
            rec(res, ct, pn + 1, 1);
            ct[di]++;
        }
        
        // Case 2: Try to place a larger digit (breaking tight constraint)  
        for (int i = di + 1; i <= 9; i++) {
            if (ct[i] > 0) {
                res[pn] = i;
                ct[i]--;
                rec(res, ct, pn + 1, 0);
                ct[i]++;
            }
        }
    } else {
        // tight == 0: Can place any available digit (choose smallest first)
        for (int i = 0; i <= 9; i++) {
            if (ct[i] > 0) {
                res[pn] = i;
                ct[i]--;
                rec(res, ct, pn + 1, 0);
                ct[i]++;
            }
        }
    }
}

void solve() {
    vector<int> even;
    vector<int> ct(10, 0);
    orig.clear();
    l = 0;
    finans = LLONG_MAX; // Reset for multiple test cases
    
    // Extract digits and count frequency
    string s = to_string(n);
    l = s.length();
    orig.resize(l);
    
    for (int i = 0; i < l; i++) {
        orig[i] = s[i] - '0';
        ct[orig[i]]++;
        if (orig[i] % 2 == 0) {
            even.push_back(orig[i]);
        }
    }
    
    // If no even digits available
    if (even.empty()) {
        cout << -1 << endl;
        return;
    }
    
    // Try each even digit as the last digit
    for (auto x : even) {
        ct[x]--;  // Reserve this digit for last position
        vector<int> res(l);
        res[l-1] = x;  // Fix last digit (0-indexed, so l-1)
        
        // Start recursion from position 0
        rec(res, ct, 0, 1);  
        
        ct[x]++;  // Restore count
    }
    
    if (finans == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << finans << endl;
    }
}

signed main() {
    cin >> n;
    solve();
    return 0;
}
