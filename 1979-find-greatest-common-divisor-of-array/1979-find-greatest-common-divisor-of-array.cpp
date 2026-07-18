class Solution {
public:
    int findGCD(vector<int>& nums) {
        auto [min_it, max_it] = std::minmax_element(nums.begin(), nums.end());
        return std::gcd(*min_it, *max_it);
    }
};