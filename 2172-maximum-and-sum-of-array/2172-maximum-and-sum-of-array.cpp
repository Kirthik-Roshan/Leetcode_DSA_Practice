class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
     int n = (int)nums.size();
    vector<int> pow3(numSlots + 1, 1);
    for (int i = 1; i <= numSlots; ++i) pow3[i] = pow3[i - 1] * 3;

    int totalStates = pow3[numSlots];
    vector<int> memo(totalStates, -1);

    function<int(int,int)> dfs = [&](int mask, int idx) -> int {
        if (idx == n) return 0;
        int& res = memo[mask];
        if (res != -1) return res;
        int best = 0;
        for (int s = 1; s <= numSlots; ++s) {
            int occ = (mask / pow3[s - 1]) % 3;
            if (occ < 2) {
                int nextMask = mask + pow3[s - 1];
                best = max(best, (nums[idx] & s) + dfs(nextMask, idx + 1));
            }
        }
        return res = best;
    };

    return dfs(0, 0);
    }
};
