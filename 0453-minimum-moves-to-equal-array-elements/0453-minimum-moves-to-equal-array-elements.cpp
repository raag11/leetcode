 class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minVal = nums[0];
        for (int x : nums) {
            minVal = min(minVal, x);
        }
        long long moves = 0;
        for (int x : nums) {
            moves += (x - minVal);
        }
        return moves;
    }
};