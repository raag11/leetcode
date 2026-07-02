 #include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        
        // dist[i][j] stores the minimum health lost to reach (i, j)
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        deque<pair<int, int>> dq;
        
        int start_cost = grid[0][0];
        dist[0][0] = start_cost;
        dq.push_back({0, 0});
        
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};
        
        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int weight = grid[nr][nc];
                    if (dist[r][c] + weight < dist[nr][nc]) {
                        dist[nr][nc] = dist[r][c] + weight;
                        if (weight == 0) dq.push_front({nr, nc});
                        else dq.push_back({nr, nc});
                    }
                }
            }
        }
        
        return health - dist[m - 1][n - 1] > 0;
    }
};