class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis = grid;
        queue<pair<int, int>> q;
        int cntfresh = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    vis[i][j] = 2;

                }

                else if (grid[i][j] == 1)
                    cntfresh++;
            }
        }

        int tm = 0;

        static const int dr[] = {-1, 0, 1, 0};
        static const int dc[] = {0, 1, 0, -1};

        while (!q.empty() && cntfresh > 0) {
            int size = q.size();

            while (size--) {
                auto [r, c] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                        vis[nr][nc] != 2 && vis[nr][nc] == 1) {
                        vis[nr][nc] = 2;
                        q.push({nr, nc});
                        cntfresh--;
                    }
                }
            }
            tm++;
        }

        return cntfresh == 0 ? tm : -1;
    }
};