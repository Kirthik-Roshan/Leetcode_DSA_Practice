class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int n = nums.size();
        int m = numSlots * 2;                // total positions
        int M = 1 << m;
        vector<int> dp(M, 0);

        for (int mask = 0; mask < M; ++mask) {
            int used = __builtin_popcount((unsigned)mask);
            if (used >= n) continue;        // already placed all numbers or too many
            int curNum = nums[used];        // place this number next
            for (int pos = 0; pos < m; ++pos) {
                if ((mask >> pos) & 1) continue;    // pos already used
                int newMask = mask | (1 << pos);
                int slot = pos / 2 + 1;
                dp[newMask] = max(dp[newMask], dp[mask] + (curNum & slot));
            }
        }

        int ans = 0;
        for (int mask = 0; mask < M; ++mask) {
            if (__builtin_popcount((unsigned)mask) == n) ans = max(ans, dp[mask]);
        }
        return ans;
    }
};
