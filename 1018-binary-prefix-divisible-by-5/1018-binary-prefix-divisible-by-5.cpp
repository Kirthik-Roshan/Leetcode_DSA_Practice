class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool>res;
        vector<int>arr={8,4,2,1};
        for(int i=0;i<nums.size();i++){
            int temp=nums[i]*arr[i];
            if(temp%5==0) res.push_back(1);
            else res.push_back(0);
        }
        return res;
    }
};