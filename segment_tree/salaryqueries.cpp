// this soln will give tle in some test cases as the codn is not very strong 


#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
#define endl '\n'

const int inf = 1e9;
vector<int> arr;
struct node {
    int mx;
    int smx;
    node() {
        mx = -inf;
        smx = inf;
    }
};
node t[800010];
int n;

node combine(const node &left, const node &right) {
    node temp;
    temp.mx = max(left.mx, right.mx);
    temp.smx = min(left.smx, right.smx);
    return temp;
}

void build(int id, int l, int r) {
    if (l == r) {
        node temp;
        temp.mx = arr[l];
        temp.smx = arr[l];
        t[id] = temp;
        return;
    }
    int mid = l + (r - l) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    t[id] = combine(t[id * 2], t[id * 2 + 1]);
}

void update(int id, int l, int r, int i, int val) {
    if (i < l || i > r)
        return;
    if (l == r) {
        arr[i] = val;
        node temp;
        temp.mx = val;
        temp.smx = val;
        t[id] = temp;
        return;
    }
    int mid = l + (r - l) / 2;
    update(id * 2, l, mid, i, val);
    update(id * 2 + 1, mid + 1, r, i, val);
    t[id] = combine(t[id * 2], t[id * 2 + 1]);
}

int answerquery(int id, int l, int r, int a, int b) {
    if (t[id].mx < a || t[id].smx > b) {
        // Entire segment out of range
        return 0;
    }
    if (t[id].smx >= a && t[id].mx <= b) {
        // Entire segment fully in range
        return r - l + 1;
    }
    if (l == r) {
        // Leaf node
        return (t[id].mx >= a && t[id].mx <= b) ? 1 : 0;
    }
    int mid = l + (r - l) / 2;
    return answerquery(id * 2, l, mid, a, b) + answerquery(id * 2 + 1, mid + 1, r, a, b);
}

void solve() {
    cin >> n;
    int q;
    cin >> q;
    arr.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    build(1, 1, n);

    while (q--) {
        char ch;
        int a, b;
        cin >> ch >> a >> b;

        if (ch == '!') {
            // Update salary of employee a to b
            update(1, 1, n, a, b);
        } else if (ch == '?') {
            // Count number of employees with salary in [a, b]
            int ans = answerquery(1, 1, n, a, b);
            cout << ans << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}
