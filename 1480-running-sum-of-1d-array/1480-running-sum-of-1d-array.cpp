class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>prefix(nums.size()+1,0);
            for(int i=0;i<nums.size();i++)prefix[i+1]=prefix[i]+nums[i];
            prefix.erase(prefix.begin());
        return prefix;
    }
};