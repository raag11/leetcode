#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
         vector<int> arr(n);
        for(int i = 0; i < n; ++i) {
            arr[i] = (nums[i] == target) ? 1 : -1;
        }
        
         vector<long long> pref(n + 1, 0);
        for(int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + arr[i];
        }
        
         vector<long long> sorted_pref = pref;
        sort(sorted_pref.begin(), sorted_pref.end());
        sorted_pref.erase(unique(sorted_pref.begin(), sorted_pref.end()), sorted_pref.end());
        
        auto get_rank = [&](long long val) {
            return lower_bound(sorted_pref.begin(), sorted_pref.end(), val) - sorted_pref.begin() + 1;
        };
        
   
        int m = sorted_pref.size();
        vector<int> bit(m + 1, 0);
        
        auto update = [&](int idx, int val) {
            for(; idx <= m; idx += idx & -idx) bit[idx] += val;
        };
        
        auto query = [&](int idx) {
            int res = 0;
            for(; idx > 0; idx -= idx & -idx) res += bit[idx];
            return res;
        };
        
        long long count = 0;
        for(long long p : pref) {
            int rank = get_rank(p);
             count += query(rank - 1);
             update(rank, 1);
        }
        
        return count;
    }
};