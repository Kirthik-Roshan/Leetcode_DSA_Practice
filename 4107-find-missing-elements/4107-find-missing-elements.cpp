class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>res;
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        for(int i=mini;i<=maxi;i++){
            if(find(nums.begin(),nums.end(),i)==nums.end()) res.push_back(i);
        }
        return res;
    }
};