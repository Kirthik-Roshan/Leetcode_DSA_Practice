class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int>even,odd,res;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0) even.push_back(nums[i]);
            else odd.push_back(nums[i]);
        }
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end());
        for(int i=0;i<nums.size()/2;i++){
            res.push_back(even[i]);
            res.push_back(odd[i]);
        }
        return res;
    }
};