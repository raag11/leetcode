 class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xor_all = 0;
        bool all_zero = true;

        for (int x : nums) {
            xor_all ^= x;
            if (x != 0) {
                all_zero = false;
            }
        }

        if (all_zero) return 0;
        if (xor_all != 0) return nums.size();
        return nums.size() - 1;
    }
};