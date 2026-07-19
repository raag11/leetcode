 class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int sRow = 0, sCol = 0, eRow = m - 1, eCol = n - 1;
        vector<int> ans;
        
        while (sRow <= eRow && sCol <= eCol) {
            for (int j = sCol; j <= eCol; j++) {
                ans.push_back(mat[sRow][j]);
            }
            sRow++;

            for (int i = sRow; i <= eRow; i++) {
                ans.push_back(mat[i][eCol]);
            }
            eCol--;

            if (sRow <= eRow) {
                for (int j = eCol; j >= sCol; j--) {
                    ans.push_back(mat[eRow][j]);
                }
                eRow--;
            }

            if (sCol <= eCol) {
                for (int i = eRow; i >= sRow; i--) {
                    ans.push_back(mat[i][sCol]);
                }
                sCol++;
            }
        }
        return ans;
    }
};