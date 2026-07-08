class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    void dfs(int r, int c, vector<vector<int>> &mat,
             vector<vector<int>> &vis) {

        vis[r][c] = 1;

        int n = mat.size();
        int m = mat[0].size();

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                !vis[nr][nc] &&
                mat[nr][nc] >= mat[r][c]) {

                dfs(nr, nc, mat, vis);
            }
        }
    }

    int countCoordinates(vector<vector<int>> &mat) {

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));

        // Pacific: top row
        for (int j = 0; j < m; j++)
            dfs(0, j, mat, pacific);

        // Pacific: left column
        for (int i = 0; i < n; i++)
            dfs(i, 0, mat, pacific);

        // Atlantic: bottom row
        for (int j = 0; j < m; j++)
            dfs(n - 1, j, mat, atlantic);

        // Atlantic: right column
        for (int i = 0; i < n; i++)
            dfs(i, m - 1, mat, atlantic);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    ans++;
            }
        }

        return ans;
    }
};