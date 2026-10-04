class Solution {
public:
    int n, m;
    void bfs(int row, int col, vector<vector<char>>& grid,
             vector<vector<int>>& vis) {
        static const int dr[] = {-1, 0, +1, 0};
        static const int dc[] = {0, 1, 0, -1};

        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        // traverse all neighbours.

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nrow = r + dr[k];
                int ncol = c + dc[k];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    !vis[nrow][ncol] && grid[nrow][ncol] == '1') {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    cnt++;
                    bfs(i, j, grid, vis);
                }
            }
        }

        return cnt;
    }
};