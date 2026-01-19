class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = (int)mat.size(), n = (int)mat[0].size();
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                prefix[i + 1][j + 1] = mat[i][j] + prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j];
            }
        }

        int left = 1, right = min(m, n), res = 0;

        while (left <= right) {
            int mid = (left + right) / 2;
            bool isValid = false;

            for (int i = mid; i <= m && !isValid; i++) {
                for (int j = mid; j <= n; j++) {
                    int square_sum = prefix[i][j] - prefix[i - mid][j] - prefix[i][j - mid] + prefix[i - mid][j - mid];
                    if (square_sum <= threshold) {
                        isValid = true;
                        break;
                    }
                }
            }

            if (isValid) {
                res = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return res;
    }
};