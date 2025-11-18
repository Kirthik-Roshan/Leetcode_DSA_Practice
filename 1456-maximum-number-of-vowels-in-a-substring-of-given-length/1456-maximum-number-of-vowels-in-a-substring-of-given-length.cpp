class Solution {
public:
    int maxVowels(string s, int k) {
        auto vowel=[&](char ch){
            return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
        };
        int ans=0,res=0;
        for(int i=0;i<k;i++){
            if(vowel(s[i])) res++;
        }
        ans=res;
        for(int i=k;i<s.size();i++){
            if(vowel(s[i])) res++;
            if(vowel(s[i-k])) res--;
            ans=max(ans,res);
        }
        return ans;
    }
};