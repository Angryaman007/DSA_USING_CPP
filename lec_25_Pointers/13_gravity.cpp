
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const int DIRS[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int bfs(int N, int M, vector<vector<int>>& grid, pair<int, int> start,
        pair<int, int> kpr) {
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<tuple<int, int, int>> q; // {row, col, steps}
    q.emplace(start.first, start.second, 0);
    visited[start.first][start.second] = true;

    auto apply_gravity = [&](int row, int col) {
        while (row + 1 < N && grid[row + 1][col] == 0) {
            row++;
        }
        return row;
    };

    while (!q.empty()) {
        auto [r, c, steps] = q.front();
        q.pop();

        if (grid[r][c] == 0) {
            r = apply_gravity(r, c);
        }

        if (r == kpr.first && c == kpr.second) {
            return steps + 1;
        }

        for (const auto& dir : DIRS) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            if (nr >= 0 && nr < N && nc >= 0 && nc < M && !visited[nr][nc]) {
                if (grid[nr][nc] == 0 || grid[nr][nc] == 1) {
                    visited[nr][nc] = true;
                    q.emplace(nr, nc, steps + 1);
                }
            }
        }
    }
    return -1; // "Impossible"
}
