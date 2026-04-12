class Solution {
public:
    int minimumDistance(vector<int>& nums) {
       unordered_map<int,vector<int>>mp;
        int dist=INT_MAX;bool found=false;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        for(auto& [val,idx]:mp){
            if(idx.size()>=3){
                for(int i=0;i+2<idx.size();i++){
                    dist=min(dist,2*(idx[i+2]-idx[i]));                   
                  found=true;
                }
            }
        }
        return found?dist:-1;
    }
};