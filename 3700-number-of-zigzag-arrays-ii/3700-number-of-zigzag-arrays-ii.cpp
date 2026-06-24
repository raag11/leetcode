 #include <vector>

using namespace std;

class Solution {
    long long MOD = 1e9 + 7;

     vector<vector<long long>> multiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B) {
        int sz = A.size();
        vector<vector<long long>> C(sz, vector<long long>(sz, 0));
        for (int i = 0; i < sz; ++i)
            for (int k = 0; k < sz; ++k)
                if (A[i][k])
                    for (int j = 0; j < sz; ++j)
                        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
        return C;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        if (n == 1) return (r - l + 1);
        int m = r - l + 1;
        int sz = 2 * m; 
        vector<vector<long long>> T(sz, vector<long long>(sz, 0));

        for (int i = 0; i < m; ++i) {
             for (int j = i + 1; j < m; ++j) T[m + j][i] = 1;
             for (int j = 0; j < i; ++j) T[j][m + i] = 1;
        }

         vector<vector<long long>> res(sz, vector<long long>(sz, 0));
        for (int i = 0; i < sz; ++i) res[i][i] = 1;
        long long p = n - 1;
        while (p > 0) {
            if (p & 1) res = multiply(res, T);
            T = multiply(T, T);
            p >>= 1;
        }
 
        vector<long long> V(sz, 1);
        
        long long total = 0;
        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < sz; ++j) {
                total = (total + res[i][j] * V[j]) % MOD;
            }
        }
        return (int)total;
    }
};