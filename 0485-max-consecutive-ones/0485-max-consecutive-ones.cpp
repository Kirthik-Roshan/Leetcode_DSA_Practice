class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int maxim=0;
       int curr=0;
       for(int num:nums){
        if(num!=0){
            curr++;
            maxim=max(curr,maxim);
        }
        else curr=0;
       }
       return maxim;
    }
};