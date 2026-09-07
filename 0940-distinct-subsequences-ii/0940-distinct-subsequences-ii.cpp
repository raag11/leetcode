 class Solution {
public:
    int distinctSubseqII(string s) {
        long long endsWith[26] = {0};
        long long mod = 1e9 + 7;

        for (char c : s) {
            int idx = c - 'a';
            long long currentTotal = 0;
            for (int i = 0; i < 26; ++i) {
                currentTotal = (currentTotal + endsWith[i]) % mod;
            }
            endsWith[idx] = (currentTotal + 1) % mod;
        }

        long long ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans = (ans + endsWith[i]) % mod;
        }

        return ans;
    }
};