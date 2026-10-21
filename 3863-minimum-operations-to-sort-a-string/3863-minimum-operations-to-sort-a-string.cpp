 #include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        if (is_sorted(s.begin(), s.end())) return 0;
        if (n == 2) return -1;

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        if (s.front() == mn || s.back() == mx) return 1;

        int mn_cnt = 0, mx_cnt = 0;
        for (char c : s) {
            if (c == mn) mn_cnt++;
            if (c == mx) mx_cnt++;
        }

        if (s.front() == mx && s.back() == mn && mn_cnt == 1 && mx_cnt == 1) {
            return 3;
        }

        return 2;
    }
};