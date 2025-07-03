#include <bits/stdc++.h>
using namespace std;
#define inf 1e9

int n, k;
vector<vector<bool>> mark;
vector<vector<int>> dp;
vector<int> arr;

int rec(int i, int j) {
    if (i == -1 && j == 0)
        return 0;

    if (i + 1 < j) return inf;

    if (mark[i][j]) return dp[i][j];

    mark[i][j] = true;
    int ans = inf;
    int lm = arr[i];

    for (int x = i; x >= 0; x--) {
        lm = max(arr[x], lm);
        int temp = rec(x - 1, j - 1);
        if (temp != inf)
            ans = min(ans, lm + temp);
    }

    return dp[i][j] = ans;
}

int main() {
    cin >> n >> k;
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mark.assign(n + 1, vector<bool>(k + 1, false));
    dp.assign(n + 1, vector<int>(k + 1, 0));

    cout << rec(n - 1, k) << endl;
}
