class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,int>ms;
        unordered_map<char,int>mt;
        for(int i=0;i<s.size();i++){
            ms[s[i]]++;
            mt[t[i]]++;
        }
      return ms==mt;
    }
};