class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        queue<int> window;
        unordered_set<int> seen;
        for (int num : nums) {
            window.push(num);
            if (window.size() > 2)
                window.pop();
            if (window.size() == 2) {
                int sum = 0;
                queue<int> temp = window;
                while (!temp.empty()) {
                    sum += temp.front();
                    temp.pop();
                }
                if (seen.count(sum)) return true;
                seen.insert(sum);
            }
        }
        return false;
    }
};
