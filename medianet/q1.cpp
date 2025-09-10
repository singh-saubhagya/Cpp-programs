#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int A, B, C, E, M;
    cin >> A >> B >> C >> E >> M;
    
    // Store attacks for each day efficiently
    vector<vector<bool>> attacked(C + 1, vector<bool>(A + 1, false));
    for (int i = 0; i < M; i++) {
        int day, city;
        cin >> day >> city;
        attacked[day][city] = true;
    }
    
    // Use only two arrays for current and next day
    vector<long long> dp(A + 1, 0);
    vector<long long> next_dp(A + 1, 0);
    
    // Base case: start at city B on day 0
    if (!attacked[0][B]) {
        dp[B] = 1;
    }
    
    // Process each day
    for (int day = 0; day < C; day++) {
        fill(next_dp.begin(), next_dp.end(), 0);
        
        // Use prefix sum array for range updates optimization
        vector<long long> diff(A + 2, 0);
        
        // For each city with non-zero ways, add contribution to reachable range
        for (int city = 1; city <= A; city++) {
            if (dp[city] == 0) continue;
            
            int left = max(1, city - E);
            int right = min(A, city + E);
            
            // Range update using difference array
            diff[left] = (diff[left] + dp[city]) % MOD;
            diff[right + 1] = (diff[right + 1] - dp[city] + MOD) % MOD;
        }
        
        // Convert difference array to actual values using prefix sum
        long long current_sum = 0;
        for (int city = 1; city <= A; city++) {
            current_sum = (current_sum + diff[city]) % MOD;
            if (!attacked[day + 1][city]) {
                next_dp[city] = current_sum;
            }
        }
        
        dp = next_dp;
    }
    
    // Sum all valid tours ending on day C
    long long result = 0;
    for (int city = 1; city <= A; city++) {
        result = (result + dp[city]) % MOD;
    }
    
    cout << result << endl;
    return 0;
}