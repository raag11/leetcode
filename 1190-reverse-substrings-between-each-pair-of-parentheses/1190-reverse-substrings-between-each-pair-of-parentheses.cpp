 class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> pair(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int j = st.top();
                st.pop();
                pair[i] = j;
                pair[j] = i;
            }
        }

        string result = "";
        int curr = 0;
        int step = 1;

        while (curr < n) {
            if (s[curr] == '(' || s[curr] == ')') {
                curr = pair[curr];
                step = -step;
            } else {
                result += s[curr];
            }
            curr += step;
        }

        return result;
    }
};