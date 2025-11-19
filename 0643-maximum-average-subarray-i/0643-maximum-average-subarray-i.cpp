class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans=INT_MIN;
        int left=0;
        double sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(i-left+1==k){
                ans=max(ans,sum/k);
                sum-=nums[left];
                left++;
            }
        }
        return ans;
    }
};