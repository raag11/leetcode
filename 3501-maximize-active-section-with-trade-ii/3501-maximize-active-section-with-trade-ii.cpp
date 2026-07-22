 #include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    struct OneSegment {
        int st, en;
        int L0, R0;
        int V;  
    };

    vector<int> tree;

    void build(int node, int start, int end, const vector<OneSegment>& ones) {
        if (start == end) {
            tree[node] = ones[start].V;
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, ones);
        build(2 * node + 1, mid + 1, end, ones);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    int query_tree(int node, int start, int end, int L, int R) {
        if (R < start || end < L) return 0;
        if (L <= start && end <= R) return tree[node];
        int mid = start + (end - start) / 2;
        return max(query_tree(2 * node, start, mid, L, R),
                   query_tree(2 * node + 1, mid + 1, end, L, R));
    }

public:
 
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int total_ones = 0;
        for (char c : s) {
            if (c == '1') total_ones++;
        }

         vector<pair<int, int>> segs;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            segs.push_back({i, j - 1});
            i = j;
        }

        vector<OneSegment> ones;
        for (int k = 0; k < (int)segs.size(); k++) {
            if (s[segs[k].first] == '1') {
                
                if (k > 0 && k < (int)segs.size() - 1) {
                    int st = segs[k].first;
                    int en = segs[k].second;
                    int L0 = segs[k - 1].first;
                    int R0 = segs[k + 1].second;
                    int V = (st - L0) + (R0 - en);
                    ones.push_back({st, en, L0, R0, V});
                }
            }
        }

        int num_ones = ones.size();
        if (num_ones > 0) {
            tree.assign(4 * num_ones, 0);
            build(1, 0, num_ones - 1, ones);
        }

        vector<int> answer;
        answer.reserve(queries.size());

        for (const auto& q : queries) {
            int L = q[0], R = q[1];
            
             
            int left_ptr = 0, right_ptr = num_ones - 1;
            int idx_L = num_ones;
            while (left_ptr <= right_ptr) {
                int mid = left_ptr + (right_ptr - left_ptr) / 2;
                if (ones[mid].st > L) {
                    idx_L = mid;
                    right_ptr = mid - 1;
                } else {
                    left_ptr = mid + 1;
                }
            }

            left_ptr = 0, right_ptr = num_ones - 1;
            int idx_R = -1;
            while (left_ptr <= right_ptr) {
                int mid = left_ptr + (right_ptr - left_ptr) / 2;
                if (ones[mid].en < R) {
                    idx_R = mid;
                    left_ptr = mid + 1;
                } else {
                    right_ptr = mid - 1;
                }
            }

            int max_gain = 0;
            if (idx_L <= idx_R) { 
                if (idx_L == idx_R) {
                    int max_L0 = max(L, ones[idx_L].L0);
                    int min_R0 = min(R, ones[idx_L].R0);
                    max_gain = (ones[idx_L].st - max_L0) + (min_R0 - ones[idx_L].en);
                } else {
                    int max_L0 = max(L, ones[idx_L].L0);
                    int gain_first = (ones[idx_L].st - max_L0) + (ones[idx_L].R0 - ones[idx_L].en);

                    int min_R0 = min(R, ones[idx_R].R0);
                    int gain_last = (ones[idx_R].st - ones[idx_R].L0) + (min_R0 - ones[idx_R].en);
                    
                    max_gain = max(gain_first, gain_last);
                    
                    if (idx_L + 1 <= idx_R - 1) {  
                        max_gain = max(max_gain, query_tree(1, 0, num_ones - 1, idx_L + 1, idx_R - 1));
                    }
                }
            }
            answer.push_back(total_ones + max_gain);
        }

        return answer;
    }
};