class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(256,0);
        int maxfreq=0;
        int left=0,res=0;
        for(int i=0;i<s.size();i++){
              freq[s[i]]++;
              maxfreq=max(maxfreq,freq[s[i]]);
              int windowsize=i-left+1;
              if((windowsize-maxfreq)>k){
                freq[s[left]]--;
                left++;
              }
              res=max(res,i-left+1);
        }
        return res;
    }
};