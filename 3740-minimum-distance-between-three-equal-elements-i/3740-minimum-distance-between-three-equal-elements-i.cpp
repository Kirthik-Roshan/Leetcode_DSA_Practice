class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int dist=INT_MAX;bool found=false;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    if(nums[i]==nums[j] && nums[j]==nums[k]){
                          dist=min(dist,abs(i-j)+abs(j-k)+abs(k-i));
                        found=true;
                    }
                }
            }
        }
        return found?dist:-1 ;
    }
};