class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int count=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]) count++;
            else if(nums[i-1]>nums[i]) count--;
        }
        return count==1?1:0;
    }
};