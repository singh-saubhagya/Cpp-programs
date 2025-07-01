#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long lli;

vector<pair<lli, lli>> ng = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

void enigma() {
    lli n, m;
    cin >> n >> m;
    vector<vector<lli>> g(n, vector<lli>(m));
    
    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    vector<vector<lli>> vis(n, vector<lli>(m, 0));
    
    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < m; j++) {
            if (g[i][j] == 0 && vis[i][j] == 0) {
                queue<pair<lli, lli>> q;
                q.push({i, j});
                vis[i][j] = 1;
                
                lli sz = 1; // Start with size 1 for the current cell
                vector<pair<lli, lli>> temp = {{i, j}}; // Store the cells in the component
                
                while (!q.empty()) {
                    pair<lli, lli> x = q.front();
                    q.pop();
                    
                    for (auto z : ng) {
                        lli row = z.first + x.first;
                        lli col = z.second + x.second;
                        if (row >= 0 && row < n && col >= 0 && col < m) {
                            if (g[row][col] == 0 && vis[row][col] == 0) {
                                q.push({row, col});
                                vis[row][col] = 1; // Mark as visited
                                sz++; // Increment size
                                temp.push_back({row, col}); // Add to the component
                            }
                        }
                    }
                }
                
                // Update the component cells
                if (sz > 1) {
                    for (auto y : temp) {
                        g[y.first][y.second] = sz; // Set to the size of the component
                    }
                } else {
                    // If size is 1, leave it as 0 (already is)
                    for (auto y : temp) {
                        g[y.first][y.second] = 0; // Ensure it's 0
                    }
                }
            }
        }
    }
    
    // Output the final matrix
    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < m; j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lli t;
    cin >> t;
    while (t--) {
        enigma();
    }
}