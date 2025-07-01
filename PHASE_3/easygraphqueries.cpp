 #include <bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'

vector<vector<lli>> g;
vector<lli> vis;
vector<lli> color;
vector<lli> szofcomp;

lli dfs(lli node, lli col, lli &sz) {
    vis[node] = 1;  // Mark as visited
    color[node] = col; // Assign component color
    sz++;

    for (auto x : g[node]) {
        if (!vis[x]) {
            dfs(x, col, sz);
        }
    }
    return sz;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    lli n, m, q;
    cin >> n >> m >> q;

    g.resize(n + 1);
    vis.resize(n + 1, 0);
    color.resize(n + 1, 0);
    szofcomp.resize(n + 1, 0);

    for (lli i = 0; i < m; i++) {
        lli a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    lli col = 1;
    for (lli i = 1; i <= n; i++) {
        if (!vis[i]) {
            lli sz = 0;
            dfs(i, col, sz);
            szofcomp[col] = sz;
            col++;
        }
    }

    while (q--) {
        lli a;
        cin >> a;
        if (a == 1) {
            lli x;
            cin >> x;
            cout << szofcomp[color[x]] << endl;
        } else {
            lli x, y;
            cin >> x >> y;
            if (color[x] == color[y])
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}
