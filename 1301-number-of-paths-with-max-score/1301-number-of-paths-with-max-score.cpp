 class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int mod = 1e9 + 7;
        
 
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<vector<int>> count(n, vector<int>(n, 0));
        
         dp[n - 1][n - 1] = 0;
        count[n - 1][n - 1] = 1;
        
         for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (board[i][j] == 'X' || dp[i][j] == -1) continue;
                
 
                int dirs[3][2] = {{0, -1}, {-1, 0}, {-1, -1}};
                
                for (auto& d : dirs) {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni >= 0 && nj >= 0 && board[ni][nj] != 'X') {
                        int val = (board[ni][nj] == 'E') ? 0 : (board[ni][nj] - '0');
                        int nextScore = dp[i][j] + val;
                        
                        if (nextScore > dp[ni][nj]) {
                            dp[ni][nj] = nextScore;
                            count[ni][nj] = count[i][j];
                        } else if (nextScore == dp[ni][nj]) {
                            count[ni][nj] = (count[ni][nj] + count[i][j]) % mod;
                        }
                    }
                }
            }
        }
        
         if (dp[0][0] == -1) return {0, 0};
        return {dp[0][0], count[0][0]};
    }
};