class Solution {
public:
    int rightsum(int y,const vector<int>& nums){
        int sum=0;
        for(int i=y+1;i<nums.size();i++) sum+=nums[i];
        return sum;
    }
    int leftsum(int x,const vector<int>& nums){
        int sum=0;
        for(int i=0;i<x;i++) sum+=nums[i];
        return sum;
    }
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>ans;
        for(int num=0;num<nums.size();num++) ans.push_back(abs(leftsum(num,nums)-rightsum(num,nums)));
        return ans;
    }
};