 class Solution {
public:
    int maxDepth(string s) {
        int current = 0;
        int ans = 0;

        for (char c : s) {
            if (c == '(') {
                current++;
                ans = max(ans, current);
            } else if (c == ')') {
                current--;
            }
        }

        return ans;
    }
};