class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>mp1;
        unordered_map<string,char>mp2;
        vector<string>dup_s;
        string word;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
            dup_s.push_back(word);
            word="";
            }
            else word+=s[i];
        }
        dup_s.push_back(word);
        //starting the actual coding stuff here on
        if(pattern.size()!=dup_s.size()) return false;
        for(int i=0;i<pattern.size();i++){
            if(mp1.count(pattern[i]) && mp1[pattern[i]]!=dup_s[i]) return false;
            if(mp2.count(dup_s[i])&& mp2[dup_s[i]]!=pattern[i]) return false;
            mp1[pattern[i]]=dup_s[i];
            mp2[dup_s[i]]=pattern[i];
        }
        return true;
    }
};