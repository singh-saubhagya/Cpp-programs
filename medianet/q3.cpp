#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
vector<vector<int>> adj;
vector<int> candies;
int result;

     pair<int, int> dfs(int node, int parent) {
        int minVal = candies[node];
        int maxVal = candies[node];
        
        for (int child : adj[node]) {
            if (child != parent) {
                auto [childMin, childMax] = dfs(child, node);
                
                // Update result with cross-subtree paths
                result = max(result, max(childMax - minVal, maxVal - childMin));
                
                // Update current subtree min/max
                minVal = min(minVal, childMin);
                maxVal = max(maxVal, childMax);
            }
        }
        
        // Update result with path ending at current node
        result = max(result, maxVal - minVal);
        
        return {minVal, maxVal};
    }

signed main()
{
  cin.tie(0); cout.tie(0);
  
}

