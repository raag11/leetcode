 class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastPos(128, -1);
        int maxLen = 0;
        int start = 0;
        
        for (int end = 0; end < s.length(); ++end) {
            char current = s[end];
            if (lastPos[current] >= start) {
                start = lastPos[current] + 1;
            }
            lastPos[current] = end;
            maxLen = max(maxLen, end - start + 1);
        }
        
        return maxLen;
    }
};