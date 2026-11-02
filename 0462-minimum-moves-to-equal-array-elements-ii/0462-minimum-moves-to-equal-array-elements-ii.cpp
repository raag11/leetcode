
class Solution {
public:
    int minMoves2(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];
        long long moves = 0;
        
        for (int x : nums) {
            moves += std::abs(x - median);
        }
        
        return moves;
    }
};