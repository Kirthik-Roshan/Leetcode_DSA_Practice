class Solution {
public:
    long long solve(vector<int>&nums,vector<long long>& mod){
        const long long NEG=-(1LL << 60);
        long long dp0=NEG,dp1=NEG,dp2=NEG;
        long long ans=NEG;
        for(int i=0;i<nums.size();i++){
            long long a=nums[i];
            long long b=mod[i];
            long long ndp0=max(dp0+a,a);
            long long ndp1=max({dp0+b,dp1+b,b});
            long long ndp2=max(dp1+a,dp2+a);
            dp0=ndp0;
            dp1=ndp1;
            dp2=ndp2;
            ans=max({ans,dp1,dp2});
        }
        return ans;
    }
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>mul(n),divv(n);
        for(int i=0;i<n;i++){
            mul[i]=1LL*nums[i]*k;
            if(nums[i]>+0)
                divv[i]=nums[i]/k;
            else
                divv[i]=-((-nums[i])/k);
        }
        return max(solve(nums,mul),solve(nums,divv));
    }
};