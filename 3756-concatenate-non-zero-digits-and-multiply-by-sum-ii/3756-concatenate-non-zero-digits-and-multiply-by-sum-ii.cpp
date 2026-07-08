 class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        int n = s.length();
        long long MOD = 1e9 + 7;
        vector<long long> pow10(n + 1);
        vector<int> idx(n + 1, 0);
        vector<long long> x(n + 1, 0);
        vector<long long> total(n + 1, 0);
        
        pow10[0] = 1;
        for (int i = 0; i < n; ++i) {
            int d = s[i] - '0';
            pow10[i + 1] = (pow10[i] * 10) % MOD;
            idx[i + 1] = idx[i] + (d != 0 ? 1 : 0);
            
            if (d != 0) {
                x[i + 1] = (x[i] * 10 + d) % MOD;
            } else {
                x[i + 1] = x[i];
            }
            total[i + 1] = total[i] + d;
        }
        vector<int> result;
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            int count = idx[r + 1] - idx[l];
            if (count == 0) {
                result.push_back(0);
            } else {
                long long val_x = (x[r + 1] - x[l] * pow10[count]) % MOD;
                if (val_x < 0) val_x += MOD;
                
                long long sum_digits = total[r + 1] - total[l];
                result.push_back((val_x * (sum_digits % MOD)) % MOD);
            }
        }
        return result;
    }
};