class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int mid=(0+(nums.size()-0))/2;
        unordered_map<int,int>freq;
        for(int num:nums) freq[num]++;
        if(freq[nums[mid]]!=1) return false;
        return true;
    }
};