class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_map<int,int>left,right;
        int count=0;
        for(int num:nums) right[num]++;
        for(int j=0;j<nums.size();j++){
            right[nums[j]]--;
            int target=nums[j];
            if(left.count(target-diff) && right.count(target+diff)) count++;
            left[nums[j]]++;
        }
        return count;
    }
};