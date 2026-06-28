class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end(),greater<int>(
        ));
        vector<long long> coef;
        for(int i=0;i<k;i++)
            coef.push_back(max(1,mul-i));
        sort(coef.begin(),coef.end(),greater<long long>());
        long long ans=0;
        for(int i=0;i<k;i++)
            ans+=1LL*nums[i]*coef[i];
        return ans;
                }
};