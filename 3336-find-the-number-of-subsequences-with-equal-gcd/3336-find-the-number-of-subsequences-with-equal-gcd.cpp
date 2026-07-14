 #include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int max_val = 0;
        for (int num : nums) {
            max_val = max(max_val, num);
        }

        int MOD = 1e9 + 7;
        vector<vector<int>> dp(max_val + 1, vector<int>(max_val + 1, 0));
        dp[0][0] = 1; 

        for (int num : nums) {
            vector<vector<int>> next_dp = dp;
            for (int g1 = 0; g1 <= max_val; ++g1) {
                for (int g2 = 0; g2 <= max_val; ++g2) {
                    if (dp[g1][g2] == 0) continue;

                    int n_g1 = (g1 == 0) ? num : std::gcd(g1, num);
                    next_dp[n_g1][g2] = (next_dp[n_g1][g2] + dp[g1][g2]) % MOD;

                    int n_g2 = (g2 == 0) ? num : std::gcd(g2, num);
                    next_dp[g1][n_g2] = (next_dp[g1][n_g2] + dp[g1][g2]) % MOD;
                }
            }
            dp = move(next_dp);
        }

        long long ans = 0;
        for (int g = 1; g <= max_val; ++g) {
            ans = (ans + dp[g][g]) % MOD;
        }

        return ans;
    }
};