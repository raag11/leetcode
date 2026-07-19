 class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last_occurrence(26, 0);
        for (int i = 0; i < s.length(); i++) {
            last_occurrence[s[i] - 'a'] = i;
        }
        
        vector<bool> seen(26, false);
        string stack = "";
        
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (seen[c - 'a']) continue;
            
            while (stack.length() > 0 && c < stack.back() && i < last_occurrence[stack.back() - 'a']) {
                seen[stack.back() - 'a'] = false;
                stack.pop_back();
            }
            
            stack.push_back(c);
            seen[c - 'a'] = true;
        }
        
        return stack;
    }
};