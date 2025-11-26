class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        const int MOD = 1'000'000'007;
        int m = grid.size();
        int n = grid[0].size();

        // dp[i][j][r] = #paths to (i,j) with sum % k == r
        vector<vector<vector<int>>> dp(
            m,
            vector<vector<int>>(n, vector<int>(k, 0))
        );

        dp[0][0][grid[0][0] % k] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Skip the starting cell, already initialized
                if (i == 0 && j == 0) continue;

                int val = grid[i][j];

                // From top (i-1, j)
                if (i > 0) {
                    for (int r = 0; r < k; ++r) {
                        if (dp[i - 1][j][r] == 0) continue;
                        int newRem = (r + val) % k;
                        dp[i][j][newRem] += dp[i - 1][j][r];
                        if (dp[i][j][newRem] >= MOD) dp[i][j][newRem] -= MOD;
                    }
                }

                // From left (i, j-1)
                if (j > 0) {
                    for (int r = 0; r < k; ++r) {
                        if (dp[i][j - 1][r] == 0) continue;
                        int newRem = (r + val) % k;
                        dp[i][j][newRem] += dp[i][j - 1][r];
                        if (dp[i][j][newRem] >= MOD) dp[i][j][newRem] -= MOD;
                    }
                }
            }
        }

        // We want paths where total sum % k == 0
        return dp[m - 1][n - 1][0];
    }
};
