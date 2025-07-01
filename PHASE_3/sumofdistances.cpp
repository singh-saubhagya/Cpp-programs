#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
void dfs(lli node, lli pnt, vector<vector<lli>> &g, vector<lli> &st)
{
    st[node] = 1;
    for (auto x : g[node])
    {
        if (x != pnt)
        {
            dfs(x, node, g, st);
            st[node] += st[x];
        }
    }
}
signed main()
{
    lli n;
    cin >> n;

    vector<vector<lli>> g;
    g.resize(n + 1);
    vector<pair<lli, lli>> edge;
    for (lli i = 1; i <= n - 1; i++)
    {
        lli a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        edge.push_back({a, b});
    }
    vector<lli> st;
    st.assign(n + 1, 0);
    dfs(1, 0, g, st);
    lli ans = 0;
    for (auto x : edge)
    {
        lli u = x.first;
        lli v = x.second;

        lli b = min(st[u], st[v]);
        lli a;
        a = st[1] - b;

        ans += a * b;
    }
    cout << ans << endl;
}
