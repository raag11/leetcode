 class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int initialOnes = 0;
        for (char c : s) {
            if (c == '1') {
                initialOnes++;
            }
        }
        string t = "1" + s + "1";
        
        vector<int> zeroBlocks;
        vector<int> oneBlocks;
        
        int i = 0;
        int n = t.length();
        
        while (i < n) {
            int j = i;
            if (t[i] == '0') {
                while (j < n && t[j] == '0') j++;
                zeroBlocks.push_back(j - i);
            } else {
                while (j < n && t[j] == '1') j++;
                oneBlocks.push_back(j - i);
            }
            i = j;
        }
        if (zeroBlocks.size() < 2) {
            return initialOnes;
        }
        int maxGain = 0;
        for (size_t k = 0; k < zeroBlocks.size() - 1; k++) {
            maxGain = max(maxGain, zeroBlocks[k] + zeroBlocks[k + 1]);
        }
        return initialOnes + maxGain;
    }
};