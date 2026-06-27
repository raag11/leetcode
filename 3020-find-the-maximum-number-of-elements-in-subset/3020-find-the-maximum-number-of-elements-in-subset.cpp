 class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> counts;
        for (int x : nums) {
            counts[x]++;
        }

        int max_len = 1;

        if (counts.count(1)) {
            int c1 = counts[1];
            if (c1 % 2 == 0) c1--;
            max_len = c1;
        }

        for (auto const& [x, freq] : counts) {
            if (x == 1) continue;
            
            long long curr = x;
            int count = 0;
            
            while (counts.count(curr) && counts[curr] >= 2) {
                count += 2;
                curr *= curr;
            }
            
            if (counts.count(curr)) {
                count += 1;
            } else {
                count -= 1;
            }
            
            max_len = max(max_len, count);
        }

        return max_len;
    }
};