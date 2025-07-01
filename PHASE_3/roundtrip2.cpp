#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

lli n, m;
vector<lli> vis;   
vector<vector<lli>> g;
bool flag;

void dfs(lli node) {
    if (flag) return;  // Stop further DFS if cycle is already found

    vis[node] = 1;  // Mark node as visiting
    for (auto x : g[node]) {
        if (vis[x] == 0) {
            dfs(x);
        } else if (vis[x] == 1) {
            flag = true;  // Back edge found → Cycle detected
            return;
        }
    }
    vis[node] = 2;  // Mark node as fully processed
}

void enigma() {
    cin >> n >> m;

    // Correctly initialize global variables for each test case
    g.assign(n + 1, {});
    vis.assign(n + 1, 0);
    flag = false;

    for (lli i = 0; i < m; i++) {
        lli a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    for (lli i = 1; i <= n; i++) {
        if (!flag && vis[i] == 0) {
            dfs(i);
        }
    }

    cout << (flag ? "Yes" : "No") << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    lli t;
    cin >> t;
    while (t--) {
        enigma();
    }
}
