class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int prefix=0,count=0;
        freq[0]=1;
        for(int num:nums){
             prefix+=num;
             if(freq.count(prefix-k)) count+=freq[prefix-k];
             freq[prefix]++;
        }
        return count;
    }
};