#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;

int water(vector<vector<int>>& fill) {
    int row = fill.size(), col = fill[0].size();
    if(row <= 2 || col <= 2) return 0; // no space to trap water
    
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    // Min-heap: store (height, x, y)
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;

    // Push all boundary cells
    for(int i = 0; i < row; i++) {
        pq.push({fill[i][0], i, 0});
        pq.push({fill[i][col-1], i, col-1});
        visited[i][0] = visited[i][col-1] = true;
    }
    for(int j = 1; j < col-1; j++) {
        pq.push({fill[0][j], 0, j});
        pq.push({fill[row-1][j], row-1, j});
        visited[0][j] = visited[row-1][j] = true;
    }

    int trapped = 0;
    vector<int> dir = {0,1,0,-1,0}; // 4 directions

    while(!pq.empty()) {
        auto [h, x, y] = pq.top(); pq.pop();

        for(int k = 0; k < 4; k++) {
            int nx = x + dir[k], ny = y + dir[k+1];
            if(nx < 0 || ny < 0 || nx >= row || ny >= col || visited[nx][ny]) continue;

            visited[nx][ny] = true;
            trapped += max(0, h - fill[nx][ny]);
            // Push neighbor with updated effective height
            pq.push({max(fill[nx][ny], h), nx, ny});
        }
    }
    return trapped;
}

int main() {
    vector<vector<int>> d = {
        {1,4,3,1,3,2},
        {3,2,1,3,2,4},
        {2,3,3,2,3,1}
    };
    cout << water(d) << endl;  // Expected output: 4
    return 0;
}