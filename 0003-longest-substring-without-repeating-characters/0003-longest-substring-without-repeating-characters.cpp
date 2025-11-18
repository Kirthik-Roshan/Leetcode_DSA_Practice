class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>freq(256,0);
        int left=0;int res=0;
        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
            while(freq[s[i]]>1){
                freq[s[left]]--;
                left++;
            }
            res=max(res,i-left+1);
        }
        return res;
    }
};