class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        // Code here
         int n = matrix.size();
        int m = matrix[0].size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    if (i - 1 >= 0 && matrix[i - 1][j] == 1) cnt++;
                    if (j - 1 >= 0 && matrix[i][j - 1] == 1) cnt++;
                    if (i + 1 < n && matrix[i + 1][j] == 1) cnt++;
                    if (j + 1 < m && matrix[i][j + 1] == 1) cnt++;
                }
            }
        }
        return cnt;
    }
};
