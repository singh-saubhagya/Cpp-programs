#include<bits/stdc++.h>
using namespace std;
#define inf 1e9

int n, k;
vector<vector<int>> dp;
vector<vector<bool>> mark;
vector<int> arr;

int rec(int i, int j) {
    if (i == -1)
    {
        if(j==0)
        return 0;
        else return inf;
    }


    if (i + 1 < j) // Not enough elements to partition
        return inf;

    

    if (mark[i][j])
        return dp[i][j];

    mark[i][j] = true;

    int ans = inf;
    int lm = arr[i]; // local max

    for (int x = i; x >= 0; x--) {
        lm = max(arr[x], lm);
        ans = min(ans, lm + rec(x - 1, j - 1));
    }

    return dp[i][j] = ans;
}

signed main() {
    cin >> n >> k;

    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Allocate only after input
    mark = vector<vector<bool>>(n, vector<bool>(k + 1, false));
    dp = vector<vector<int>>(n, vector<int>(k + 1, 0));

    cout << rec(n - 1, k) << endl;

    return 0;
}
