 class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max_val = 0;
        for (int x : nums) max_val = max(max_val, x);
        
        vector<int> count(max_val + 1, 0);
        for (int x : nums) count[x]++;
        
        vector<long long> gcd_counts(max_val + 1, 0);
        for (int i = max_val; i >= 1; --i) {
            long long multiples = 0;
            for (int j = i; j <= max_val; j += i) {
                multiples += count[j];
            }
            
            gcd_counts[i] = multiples * (multiples - 1) / 2;
            for (int j = 2 * i; j <= max_val; j += i) {
                gcd_counts[i] -= gcd_counts[j];
            }
        }
        
        vector<long long> prefix_gcd(max_val + 1, 0);
        for (int i = 1; i <= max_val; ++i) {
            prefix_gcd[i] = prefix_gcd[i - 1] + gcd_counts[i];
        }
        
        vector<int> result;
        for (long long q : queries) {
            auto it = upper_bound(prefix_gcd.begin(), prefix_gcd.end(), q);
            result.push_back(distance(prefix_gcd.begin(), it));
        }
        
        return result;
    }
};