 class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minVal = nums[0];
        int maxVal = nums[0];
        bool seen[102] = {false};

        for (int num : nums) {
            minVal = min(minVal, num);
            maxVal = max(maxVal, num);
            seen[num] = true;
        }

        vector<int> missing;
        for (int i = minVal + 1; i < maxVal; ++i) {
            if (!seen[i]) {
                missing.push_back(i);
            }
        }

        return missing;
    }
};