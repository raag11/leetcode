 class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; ++i) {
            int target_count = 0;
            for (int j = i; j < n; ++j) {
                if (nums[j] == target) {
                    target_count++;
                }
                int length = j - i + 1;
                if (target_count * 2 > length) {
                    count++;
                }
            }
        }
        return count;
    }
};