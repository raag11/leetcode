 class Solution {
    int m, n;
    int memo[100][100][205];

    bool dfs(int r, int c, int bal, vector<vector<char>>& grid) {
        bal += (grid[r][c] == '(' ? 1 : -1);

        if (bal < 0 || bal > (m - 1 - r) + (n - 1 - c)) {
            return false;
        }

        if (r == m - 1 && c == n - 1) {
            return bal == 0;
        }

        if (memo[r][c][bal] != -1) {
            return memo[r][c][bal];
        }

        bool res = false;
        if (r + 1 < m) {
            res = dfs(r + 1, c, bal, grid);
        }
        if (!res && c + 1 < n) {
            res = dfs(r, c + 1, bal, grid);
        }

        return memo[r][c][bal] = res;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if ((m + n - 1) % 2 != 0 || grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
            return false;
        }

        memset(memo, -1, sizeof(memo));
        return dfs(0, 0, 0, grid);
    }
};