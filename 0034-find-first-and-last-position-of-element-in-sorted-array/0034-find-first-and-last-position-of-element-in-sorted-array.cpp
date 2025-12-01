class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1,n=nums.size();
        vector<int>res(2,-1);
        auto it=find(nums.begin(),nums.end(),target);
        if(it==nums.end()) return res;
        while(low<n){
             if(nums[low]==target){
                res[0]=low;
                res[1]=low+1;
                break;
             }
             else low++;
        }
        return res;
    }
};