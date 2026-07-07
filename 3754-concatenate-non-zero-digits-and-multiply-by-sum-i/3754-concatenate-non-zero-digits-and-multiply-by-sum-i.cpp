 class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 0) return 0;
        long long x = 0;
        long long sum = 0;
        long long multiplier = 1;
         string s = to_string(n);
        for (int i = s.length() - 1; i >= 0; --i) {
            int digit = s[i] - '0';
            if (digit != 0) {
                x += (long long)digit * multiplier;
                sum += digit;
                multiplier *= 10;
            }
        }
        return x * sum;
    }
};