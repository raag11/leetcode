 class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        vector<int> v = nums;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        
        bool p[2048] = {0};
        bool res[2048] = {0};
        for(int i = 0; i < v.size(); i++) {
            for(int j = i; j < v.size(); j++) {
                p[v[i] ^ v[j]] = true;
            }
        }
        for(int i = 0; i < 2048; i++) {
            if(p[i]) {
                for(int x : v) {
                    res[i ^ x] = true;
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < 2048; i++) {
            if(res[i]) cnt++;
        }
        return cnt;
    }
};