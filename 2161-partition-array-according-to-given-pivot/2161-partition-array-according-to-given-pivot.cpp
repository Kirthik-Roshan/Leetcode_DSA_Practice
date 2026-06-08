class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        int low=0,high=n-1;
        int left=0,right=n-1;
        vector<int>ans(n);
        while(low<n){
            if(nums[low]<pivot) ans[left++]=nums[low];
            if(nums[high]>pivot) ans[right--]=nums[high];
            low++;
            high--;
        }
        while(left<=right) ans[left++]=pivot;
        return ans;
    }
};