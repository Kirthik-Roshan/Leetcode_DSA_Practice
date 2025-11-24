class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char>s(allowed.begin(),allowed.end());
        int count=0;
        for(string word:words){
            bool good=true;
            for(char ch:word){
                if(!s.count(ch)) good=false;
            }
            if(good) count++;
        }
        return count;
    }
};