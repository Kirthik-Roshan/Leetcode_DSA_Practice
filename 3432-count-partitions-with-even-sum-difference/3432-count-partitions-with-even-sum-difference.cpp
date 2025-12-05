class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int totalsum=0;int count=0;
        for(int num:nums){
            totalsum+=num;
        }
        int leftsum=0;
        for(int i=0;i<nums.size()-1;i++){
            leftsum+=nums[i];
            int rigthsum=totalsum-leftsum;
            if((leftsum-rigthsum)%2==0) count++;
        }
        return count;
    }
};