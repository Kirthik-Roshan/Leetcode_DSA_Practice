class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>r,m;
        for(char ch:ransomNote) r[ch]++;
        for(char ch:magazine) m[ch]++;
        for(auto &[key,val]:r){
              if(r[key]>[key]) return false;
        }
        return true;
    }
};